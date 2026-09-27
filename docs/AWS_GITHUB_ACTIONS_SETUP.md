# HiCo Thermal — GitHub Actions → AWS

HiCo Thermal uses GitHub Actions as the control plane and AWS CodeBuild as ephemeral compute for the thermal database ingestion/mapping workload.

```text
GitHub Actions
   │
   │ OIDC
   ▼
Bootstrap IAM role
   │
   ├── CloudFormation deploy/update
   │       ├── private S3 run bucket
   │       ├── CodeBuild project
   │       ├── CodeBuild worker role
   │       ├── CodeBuild batch role
   │       └── HiCo controller role
   │
   └── CodeBuild batch
            │
            ├── ingest shard 1
            ├── ingest shard 2
            └── ...
            │
            ▼
          S3 results
            │
            ▼
      GitHub merge/validate/publish
```

## One-time bootstrap

There must be one AWS identity that GitHub Actions can assume before CloudFormation can create the final HiCo controller role. This is the only manual AWS bootstrap step. Afterward, infrastructure deployment is controlled by `.github/workflows/aws-infra.yml`.

### 1. Create the GitHub OIDC provider

In AWS IAM, add an OpenID Connect provider:

```text
Provider URL: https://token.actions.githubusercontent.com
Audience:     sts.amazonaws.com
```

The GitHub OIDC trust must be restricted by the `sub` claim. GitHub documents this as an important condition so credentials are not issued to unintended repositories. citeturn998815search1

### 2. Create the bootstrap IAM role

Create a role named, for example:

```text
hico-thermal-bootstrap
```

Use `infra/aws/bootstrap-trust-policy.json` for its trust policy and replace `<AWS_ACCOUNT_ID>` with the AWS account ID.

Attach `infra/aws/bootstrap-policy.json` as an inline policy.

The bootstrap role is intentionally limited to the AWS APIs needed to create/update the HiCo CloudFormation stack and its S3, CloudWatch Logs, CodeBuild, and IAM resources. The stack's runtime CodeBuild role and GitHub controller role are separate roles.

### 3. Add one repository variable

In GitHub:

```text
Settings
→ Secrets and variables
→ Actions
→ Variables
```

Create:

```text
HICO_AWS_BOOTSTRAP_ROLE_ARN=<ARN of hico-thermal-bootstrap>
```

Optional non-secret variables:

```text
HICO_AWS_REGION=us-east-1
HICO_AWS_STACK_NAME=hico-thermal-offload
```

The database workflow can use `HICO_AWS_ROLE_ARN` when present, but falls back to `HICO_AWS_BOOTSTRAP_ROLE_ARN`. It can also resolve the CodeBuild project and S3 bucket from CloudFormation outputs, so those variables are not mandatory.

## Automatic infrastructure deployment

`.github/workflows/aws-infra.yml` runs when `infra/aws/**` changes on `main`, and it can also be started manually from GitHub Actions.

The workflow:

1. obtains temporary AWS credentials with GitHub OIDC;
2. discovers the GitHub OIDC provider if `HICO_AWS_OIDC_PROVIDER_ARN` is not set;
3. validates the CloudFormation template;
4. creates or updates `hico-thermal-offload`;
5. prints stack outputs and a deployment summary.

The workflow uses `aws-actions/configure-aws-credentials@v6.3.0`, which supports the OIDC flow shown in GitHub's current AWS guidance. citeturn998815search1turn998815search5

No AWS access key or AWS secret key is required in GitHub.

## Database workflow

When `compute_backend=aws` is selected in `.github/workflows/database.yml`:

```text
preflight
   ↓
discover
   ↓
AWS submit
   ├── upload discovery.json → S3
   ├── upload worker source → S3
   ├── upload hicod → S3
   └── StartBuildBatch
             ↓
       CodeBuild batch
             ↓
           S3 results
             ↓
          AWS wait
             ↓
           merge
             ↓
      validate + publish database/
```

The AWS worker receives only the run-specific discovery/source/binary inputs. The private Git repository itself is not cloned by CodeBuild.

## Local AWS CLI is no longer part of the normal flow

Do not use `infra/aws/deploy.sh` from Termux/Ubuntu for routine deployments. It remains in the repository as the reusable deployment implementation and for controlled diagnostics, but GitHub Actions is now the normal deployment entrypoint.

## Why the first bootstrap cannot be completely self-hosted by Actions

GitHub Actions cannot obtain an AWS web-identity credential from an IAM role that does not exist yet. Therefore the OIDC provider and bootstrap role must exist before the first workflow run. Once that role exists, all subsequent CloudFormation deployments can be performed by Actions without long-lived AWS credentials. GitHub's OIDC documentation describes this federation model. citeturn998815search1

## Concurrency

The CloudFormation default remains one concurrently running Linux/Medium CodeBuild build. AWS documents concurrent-build quotas per Region and compute type; a project can queue builds when its concurrency limit is reached. Increase the project limit only after the AWS account quota permits it and the first full run is verified. citeturn384089search9turn384089search8

CodeBuild batch builds use a dedicated batch service role separate from the build role because the batch service role needs the ability to start, stop, and retry builds on behalf of the batch. AWS explicitly recommends keeping those permissions out of the normal build role. citeturn384089search0turn384089search2
