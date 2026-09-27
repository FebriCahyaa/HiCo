# HiCo Thermal AWS CodeBuild Offload

GitHub remains the persistent source of truth. GitHub Actions is the control plane; AWS CodeBuild is an ephemeral compute layer for large thermal ingestion and mapping runs.

## Infrastructure flow

```text
GitHub push / manual workflow
          |
          v
.github/workflows/aws-infra.yml
          |
      GitHub OIDC
          |
          v
  bootstrap IAM role
          |
          v
 CloudFormation stack
          |
   +------+-------+
   |      |       |
   v      v       v
  S3   CodeBuild  IAM roles
   |      |
   |      +--> worker batch
   |             |
   +<------------+

```

The infrastructure workflow automatically runs when `infra/aws/**` changes on `main`. It can also be started manually from the GitHub Actions UI.

## Compute flow

```text
GitHub Actions
  discover registered sources
       |
       +--> upload discovery.json, source snapshot and hicod -> private S3
       |
       +--> StartBuildBatch with a dynamic CodeBuild matrix
                     |
                     v
               CodeBuild workers
                 ingest -> unpack/decode -> map
                     |
                     v
                    S3
                     |
                     v
               GitHub merge job
                 merge -> validate -> push database/
```

The workflow uses GitHub OIDC through `aws-actions/configure-aws-credentials@v6.3.0`; no long-lived AWS access keys are stored in GitHub. GitHub's OIDC documentation requires a trust condition that limits which repository/workflow identity can receive AWS credentials. citeturn998815search1turn998815search5

## One-time bootstrap

Actions cannot assume an IAM role that does not exist yet. Create the GitHub OIDC provider and one bootstrap role once. After that, Actions controls routine CloudFormation deployment.

Detailed instructions, trust policy, and the bootstrap IAM policy are in [`docs/AWS_GITHUB_ACTIONS_SETUP.md`](AWS_GITHUB_ACTIONS_SETUP.md).

The only required GitHub repository variable for the initial flow is:

```text
HICO_AWS_BOOTSTRAP_ROLE_ARN=<bootstrap role ARN>
```

Optional values:

```text
HICO_AWS_REGION=us-east-1
HICO_AWS_STACK_NAME=hico-thermal-offload
HICO_AWS_OIDC_PROVIDER_ARN=<provider ARN>
HICO_AWS_OIDC_SUBJECT=repo:FebriCahyaa/HiCo:ref:refs/heads/main
HICO_AWS_ROLE_ARN=<CloudFormation-created HiCo controller role ARN>
HICO_AWS_CODEBUILD_PROJECT=<CloudFormation-created project name>
HICO_AWS_S3_BUCKET=<CloudFormation-created bucket name>
```

The database workflow resolves the CodeBuild project and S3 bucket from CloudFormation outputs when those optional variables are absent. It prefers `HICO_AWS_ROLE_ARN` for runtime least privilege and falls back to the bootstrap role until the controller role is configured.

## Repository privacy

AWS does not clone the private HiCo repository. GitHub Actions creates a run-specific snapshot containing only the worker inputs (`tools/`, `sources/`, discovery metadata, and the built `hicod`) and uploads those inputs to the private S3 run prefix.

## Concurrency

The CloudFormation default remains one concurrently running Linux/Medium CodeBuild build. AWS documents concurrent-build quotas per Region and compute type; project-level limits can throttle additional builds. Increase concurrency only after the account quota has been increased and a full run is verified. citeturn384089search9turn384089search8

The CodeBuild project uses a separate batch service role because batch builds require permissions to start, stop, and retry builds on behalf of the batch. AWS recommends keeping those permissions out of the normal build role. citeturn384089search0turn384089search2

## Data handling

Only run inputs and worker results are stored under `runs/<run-id>/` in S3. The bucket is private, encrypted, versioned, and configured with a lifecycle for temporary run data. GitHub remains the authoritative persistent database.

Unknown encrypted thermal binaries remain metadata-only. HiCo does not invent or bypass unknown decryption schemes.

## Cost control

CodeBuild is metered compute. AWS credits may offset eligible usage, but they do not remove AWS service quotas or make compute unlimited. Keep the initial concurrency at `1` and increase it deliberately.

## Local deployment script

`infra/aws/deploy.sh` remains in the repository as the reusable CloudFormation implementation and diagnostic helper. It is not the normal entrypoint anymore. It now:

- auto-discovers the GitHub OIDC provider when no ARN is supplied;
- validates the CloudFormation template before deployment;
- accepts an empty change set without failing the workflow;
- prints failed CloudFormation events when a deployment fails.
