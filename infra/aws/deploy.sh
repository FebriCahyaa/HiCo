#!/usr/bin/env bash
set -euo pipefail

STACK_NAME="${1:-hico-thermal-offload}"
REGION="${AWS_REGION:-us-east-1}"
OIDC_PROVIDER_ARN="${2:-}"
OIDC_SUBJECT="${HICO_AWS_OIDC_SUBJECT:-repo:FebriCahyaa/HiCo:ref:refs/heads/main}"
COMPUTE_TYPE="${HICO_CODEBUILD_COMPUTE_TYPE:-BUILD_GENERAL1_MEDIUM}"
CONCURRENT_LIMIT="${HICO_CODEBUILD_CONCURRENT_LIMIT:-1}"
BATCH_MAX="${HICO_CODEBUILD_BATCH_MAX:-250}"

if [[ -z "$OIDC_PROVIDER_ARN" ]]; then
  echo "Usage: $0 <stack-name> <github-oidc-provider-arn>" >&2
  exit 2
fi

echo "Deploying HiCo Thermal AWS infrastructure..."
echo "  stack           : $STACK_NAME"
echo "  region          : $REGION"
echo "  OIDC subject    : $OIDC_SUBJECT"
echo "  compute type    : $COMPUTE_TYPE"
echo "  concurrency     : $CONCURRENT_LIMIT"
echo "  batch max       : $BATCH_MAX"

aws sts get-caller-identity >/dev/null

aws_cmd=(
  aws cloudformation deploy
  --region "$REGION"
  --stack-name "$STACK_NAME"
  --template-file "$(cd "$(dirname "$0")" && pwd)/cloudformation/hico-thermal.yml"
  --capabilities CAPABILITY_NAMED_IAM
  --parameter-overrides
  "GitHubOidcProviderArn=$OIDC_PROVIDER_ARN"
  "GitHubOidcSubject=$OIDC_SUBJECT"
  "ComputeType=$COMPUTE_TYPE"
  "ConcurrentBuildLimit=$CONCURRENT_LIMIT"
  "BatchMaximumBuilds=$BATCH_MAX"
)
"${aws_cmd[@]}"

echo
aws cloudformation describe-stacks \
  --region "$REGION" \
  --stack-name "$STACK_NAME" \
  --query 'Stacks[0].Outputs[*].[OutputKey,OutputValue]' \
  --output table
