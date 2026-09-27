# HiCo Thermal AWS CodeBuild Offload

GitHub remains the persistent source of truth. AWS CodeBuild is an ephemeral compute layer for large thermal ingestion and mapping runs.

## Flow

```text
GitHub Actions
  discover registered sources
       |
       +--> upload discovery.json, source snapshot and hicod -> S3
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

The workflow uses GitHub OIDC through `aws-actions/configure-aws-credentials@v6.3.0`; no long-lived AWS access keys are stored in GitHub.

## One-time AWS setup

Create the IAM OIDC provider for `https://token.actions.githubusercontent.com` with audience `sts.amazonaws.com`. Restrict the GitHub Actions role trust with `token.actions.githubusercontent.com:sub` to the HiCo repository and `main` branch.

Deploy `infra/aws/cloudformation/hico-thermal.yml` with the OIDC provider ARN. The stack creates:

- a private, encrypted, versioned S3 run bucket with a 14-day lifecycle;
- an Ubuntu 24.04 CodeBuild worker project (`aws/codebuild/standard:8.0`);
- a dedicated CodeBuild worker role;
- a separate CodeBuild batch service role;
- a GitHub Actions OIDC controller role.

Set these repository variables:

```text
HICO_AWS_ROLE_ARN=<GitHubActionsRoleArn>
HICO_AWS_CODEBUILD_PROJECT=<CodeBuildProjectName>
HICO_AWS_S3_BUCKET=<ArtifactBucketName>
HICO_AWS_REGION=us-east-1
```

For repositories using immutable GitHub OIDC subject claims, use the `sub` format emitted by the repository instead of the default `repo:OWNER/REPO:ref:refs/heads/BRANCH` form.

## First run

In Actions -> HiCo Thermal Database choose `compute_backend=aws` and keep the repository shard size at 50. The project default concurrency is intentionally 1 so the infrastructure can be created even when the regional CodeBuild quota has not been increased.

After the first end-to-end run succeeds, increase the regional CodeBuild concurrent-build quota and then raise `ConcurrentBuildLimit` in the CloudFormation stack as needed. CodeBuild documents per-Region concurrent-build quotas and separate batch restrictions.

## Data handling

Only run inputs and worker results are stored under `runs/<run-id>/` in S3. GitHub downloads the validated results and remains the authoritative persistent database. Unknown encrypted thermal binaries remain metadata-only; HiCo does not invent or bypass unknown decryption schemes.

## Cost control

CodeBuild is metered compute. AWS credits may offset the bill, but they do not make the compute unlimited. Keep concurrency and shard size controlled until a complete run is verified.
