# AWS setup for HiCo Thermal

This setup uses GitHub Actions OIDC and AWS CodeBuild batch builds. It does not require a long-lived AWS access key in GitHub. GitHub's current OIDC guidance recommends restricting the IAM trust policy with the `sub` claim and the official AWS credentials action is `aws-actions/configure-aws-credentials@v6.3.0`.


## 0. Prerequisites

The local deployment shell needs AWS CLI credentials that can create or update CloudFormation, IAM, S3, CloudWatch Logs, and CodeBuild resources. GitHub itself does not receive a long-lived AWS access key. The workflow uses GitHub OIDC to assume the controller role. GitHub documents restricting that trust with the `sub` claim, and the AWS credentials action recommends OIDC for this pattern.

The first deployment intentionally defaults to one concurrently running Linux/Medium CodeBuild build. AWS currently documents one as the default quota for Linux/Medium in a Region; the quota is adjustable. Increase the CloudFormation `ConcurrentBuildLimit` only after the first end-to-end run is working and the account quota has been increased if necessary.

## 1. Create the GitHub OIDC provider

In AWS Console:

`IAM -> Identity providers -> Add provider`

Choose:

```text
Provider type : OpenID Connect
Provider URL  : https://token.actions.githubusercontent.com
Audience      : sts.amazonaws.com
```

Copy the resulting provider ARN.

## 2. Deploy the HiCo stack

From a shell with AWS credentials that can create IAM, S3, CloudWatch Logs and CodeBuild resources:

```bash
cd infra/aws
./deploy.sh hico-thermal-offload <OIDC_PROVIDER_ARN>
```

The default compute type is `BUILD_GENERAL1_MEDIUM` and the project concurrent-build limit defaults to `1`. This is intentional: AWS CodeBuild has per-Region concurrent-build quotas, which can be lower than the batch maximum. Increase the quota and project concurrency only after the first successful run.

## 3. Copy stack outputs to GitHub repository variables

In GitHub:

`Settings -> Secrets and variables -> Actions -> Variables -> New repository variable`

Create:

```text
HICO_AWS_ROLE_ARN
HICO_AWS_CODEBUILD_PROJECT
HICO_AWS_S3_BUCKET
HICO_AWS_REGION
```

Use the corresponding CloudFormation outputs. The ARN values are identifiers, not credentials.

## 4. Test AWS authentication without starting a batch

Use `database.yml` with `compute_backend=aws`. The first AWS job calls `aws sts get-caller-identity` before uploading or starting CodeBuild.

## 5. First compute run

Use:

```text
Repositories per GitHub discovery shard: 50
Compute backend: aws
Region: us-east-1
```

GitHub creates the discovery manifest, a compact worker source snapshot containing `tools/` and `sources/`, and the host `hicod`, then uploads them into a run-specific S3 prefix. One AWS CodeBuild batch is then started with a dynamic matrix containing the discovered shard IDs.

Each CodeBuild worker downloads only the run inputs, selects its assigned shard, executes the existing HiCo Thermal ingestion/mapping tools, and uploads its shard result to S3.

GitHub waits for the single CodeBuild batch, downloads the final S3 result tree, performs the existing merge and validation steps, and only then pushes `database/`.

## 6. Increase concurrency

After a successful end-to-end run, raise the AWS regional CodeBuild concurrent build quota if needed and update the stack's `ConcurrentBuildLimit`. The workflow does not bypass the AWS account/service quota; queued workers remain controlled by CodeBuild.

## Security

The GitHub controller role can start/stop the one HiCo CodeBuild project and read/write only the `runs/*` prefix in the stack-created S3 bucket. The worker role can read/write the same run prefix and write its own CodeBuild logs. The batch service role is separate from the worker role as recommended by AWS for CodeBuild batch builds.

## Cleanup

The S3 run bucket has a lifecycle rule that expires run data after 14 days. Deleting the CloudFormation stack does not delete the S3 bucket because the bucket is retained by design; remove it explicitly only when you are certain the historical run data is no longer needed.
