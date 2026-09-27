from pathlib import Path
import yaml


def main() -> int:
    workflow = yaml.safe_load(Path('.github/workflows/database.yml').read_text(encoding='utf-8'))
    jobs = workflow['jobs']
    assert 'aws-submit' in jobs
    assert 'aws-wait' in jobs
    assert jobs['aws-submit']['if'] == "inputs.compute_backend == 'aws'"
    assert jobs['aws-wait']['if'] == "inputs.compute_backend == 'aws'"
    assert jobs['ingest']['if'] == "inputs.compute_backend != 'aws' && needs.discover.outputs.matrix_ids != '[]'"
    assert jobs['map']['if'] == "inputs.compute_backend != 'aws'"
    assert workflow.get('permissions', {}).get('id-token') == 'write' or jobs['aws-submit'].get('permissions', {}).get('id-token') == 'write'
    assert 'release' not in jobs
    assert 'release.yml' not in Path('.github/workflows/database.yml').read_text(encoding='utf-8')
    assert 'aws-actions/configure-aws-credentials@v6.3.0' in Path('.github/workflows/database.yml').read_text(encoding='utf-8')
    print('AWS workflow architecture test: PASS')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
