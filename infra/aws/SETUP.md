# AWS setup for HiCo Thermal

Normal AWS infrastructure deployment is controlled by GitHub Actions, not by a local Termux/Ubuntu session.

Read [`docs/AWS_GITHUB_ACTIONS_SETUP.md`](../../docs/AWS_GITHUB_ACTIONS_SETUP.md) for the one-time OIDC/bootstrap role setup and the complete deployment flow.

After the bootstrap role is created, add this repository variable:

```text
HICO_AWS_BOOTSTRAP_ROLE_ARN=<bootstrap role ARN>
```

Optional:

```text
HICO_AWS_REGION=us-east-1
HICO_AWS_STACK_NAME=hico-thermal-offload
HICO_AWS_ROLE_ARN=<CloudFormation-created HiCo controller role ARN>
```

Then run **Actions → HiCo Thermal AWS Infrastructure → Run workflow** once. Subsequent changes under `infra/aws/**` on `main` automatically run the same deployment workflow.

`infra/aws/deploy.sh` remains a reusable implementation detail. It now auto-discovers the GitHub OIDC provider when no provider ARN is supplied, validates the template, tolerates an empty CloudFormation change set, and prints failed stack events when deployment fails.
