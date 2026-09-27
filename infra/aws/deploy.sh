#!/usr/bin/env bash
set -euo pipefail

STACK_NAME="${1:-hico-thermal-offload}"
REGION="${AWS_REGION:-us-east-1}"
OIDC_PROVIDER_ARN="${2:-${HICO_AWS_OIDC_PROVIDER_ARN:-}}"
OIDC_SUBJECT="${HICO_AWS_OIDC_SUBJECT:-repo:FebriCahyaa/HiCo:ref:refs/heads/main}"
COMPUTE_TYPE="${HICO_CODEBUILD_COMPUTE_TYPE:-BUILD_GENERAL1_MEDIUM}"
CONCURRENT_LIMIT="${HICO_CODEBUILD_CONCURRENT_LIMIT:-1}"
BATCH_MAX="${HICO_CODEBUILD_BATCH_MAX:-250}"

export AWS_PAGER=""

resolve_github_oidc_provider() {
  if [[ -n "$OIDC_PROVIDER_ARN" ]]; then
    printf '%s\n' "$OIDC_PROVIDER_ARN"
    return 0
  fi

  echo "Discovering GitHub Actions OIDC provider..." >&2
  local provider arn url
  while IFS= read -r provider; do
    [[ -z "$provider" ]] && continue
    url="$(aws iam get-open-id-connect-provider \
      --open-id-connect-provider-arn "$provider" \
      --query 'Url' \
      --output text 2>/dev/null || true)"
    case "$url" in
      https://token.actions.githubusercontent.com|token.actions.githubusercontent.com)
        printf '%s\n' "$provider"
        return 0
        ;;
    esac
  done < <(aws iam list-open-id-connect-providers --query 'OpenIDConnectProviderList[].Arn' --output text | tr '\t' '\n')

  echo "GitHub Actions OIDC provider was not found in $REGION's AWS account." >&2
  echo "Create https://token.actions.githubusercontent.com with audience sts.amazonaws.com, or set HICO_AWS_OIDC_PROVIDER_ARN." >&2
  return 1
}

OIDC_PROVIDER_ARN="$(resolve_github_oidc_provider)"

if [[ -z "$OIDC_PROVIDER_ARN" ]]; then
  echo "Unable to resolve GitHub OIDC provider ARN." >&2
  exit 1
fi

echo "Deploying HiCo Thermal AWS infrastructure..."
echo "  stack           : $STACK_NAME"
echo "  region          : $REGION"
echo "  OIDC subject    : $OIDC_SUBJECT"
echo "  OIDC provider   : $OIDC_PROVIDER_ARN"
echo "  compute type    : $COMPUTE_TYPE"
echo "  concurrency     : $CONCURRENT_LIMIT"
echo "  batch max       : $BATCH_MAX"

authtest="$(aws sts get-caller-identity --query 'Arn' --output text)"
echo "  caller          : $authtest"

template="$(cd "$(dirname "$0")" && pwd)/cloudformation/hico-thermal.yml"
aws cloudformation validate-template \
  --region "$REGION" \
  --template-body "file://$template" \
  --query 'Description' \
  --output text >/dev/null

aws_cmd=(
  aws cloudformation deploy
  --region "$REGION"
  --stack-name "$STACK_NAME"
  --template-file "$template"
  --capabilities CAPABILITY_NAMED_IAM
  --no-fail-on-empty-changeset
  --parameter-overrides
  "GitHubOidcProviderArn=$OIDC_PROVIDER_ARN"
  "GitHubOidcSubject=$OIDC_SUBJECT"
  "ComputeType=$COMPUTE_TYPE"
  "ConcurrentBuildLimit=$CONCURRENT_LIMIT"
  "BatchMaximumBuilds=$BATCH_MAX"
)

set +e
"${aws_cmd[@]}"
deploy_rc=$?
set -e

if [[ "$deploy_rc" -ne 0 ]]; then
  echo >&2
  echo "CloudFormation deployment failed with exit code $deploy_rc." >&2
  echo "Recent failed CloudFormation events:" >&2
  aws cloudformation describe-stack-events \
    --region "$REGION" \
    --stack-name "$STACK_NAME" \
    --query 'StackEvents[?contains(ResourceStatus, `FAILED`)].[Timestamp,LogicalResourceId,ResourceStatus,ResourceStatusReason]' \
    --output table 2>/dev/null || true
  exit "$deploy_rc"
fi

echo
echo "CloudFormation stack outputs:"
aws cloudformation describe-stacks \
  --region "$REGION" \
  --stack-name "$STACK_NAME" \
  --query 'Stacks[0].Outputs[*].[OutputKey,OutputValue]' \
  --output table
