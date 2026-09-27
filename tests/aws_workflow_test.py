from pathlib import Path
import yaml


ROOT = Path(__file__).resolve().parents[1]


def main() -> int:
    database_path = ROOT / '.github/workflows/database.yml'
    infra_path = ROOT / '.github/workflows/aws-infra.yml'
    database_text = database_path.read_text(encoding='utf-8')
    infra_text = infra_path.read_text(encoding='utf-8')

    database = yaml.safe_load(database_text)
    infra = yaml.safe_load(infra_text)

    jobs = database['jobs']
    assert 'aws-submit' in jobs
    assert 'aws-wait' in jobs
    assert "(inputs.compute_backend || vars.HICO_DATABASE_BACKEND || 'aws') == 'aws'" in database_text
    assert "(inputs.compute_backend || vars.HICO_DATABASE_BACKEND || 'aws') != 'aws'" in database_text
    assert "needs.discover.outputs.matrix_ids != '[]'" in database_text
    assert 'release' not in jobs
    assert 'release.yml' not in database_text
    assert 'aws-actions/configure-aws-credentials@v6.3.0' in database_text
    assert 'vars.HICO_AWS_ROLE_ARN || vars.HICO_AWS_BOOTSTRAP_ROLE_ARN' in database_text
    assert 'CodeBuildProjectName' in database_text
    assert 'default: aws' in database_text
    assert 'ArtifactBucketName' in database_text

    infra_jobs = infra['jobs']
    assert 'deploy' in infra_jobs
    assert "id-token: write" in infra_text
    assert 'aws-actions/configure-aws-credentials@v6.3.0' in infra_text
    assert 'vars.HICO_AWS_BOOTSTRAP_ROLE_ARN' in infra_text
    assert 'infra/aws/deploy.sh' in infra_text
    assert "paths:\n      - 'infra/aws/**'" in infra_text
    assert 'workflow_dispatch:' in infra_text
    assert 'gitlab' not in infra_text.lower()

    print('AWS workflow architecture test: PASS')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
