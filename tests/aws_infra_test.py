#!/usr/bin/env python3
from __future__ import annotations

from pathlib import Path
import subprocess
import yaml

ROOT = Path(__file__).resolve().parents[1]


class CloudFormationLoader(yaml.SafeLoader):
    pass


def _cfn_tag(loader, tag_suffix, node):
    if isinstance(node, yaml.ScalarNode):
        return loader.construct_scalar(node)
    if isinstance(node, yaml.SequenceNode):
        return loader.construct_sequence(node)
    return loader.construct_mapping(node)


CloudFormationLoader.add_multi_constructor('!', _cfn_tag)


def main() -> int:
    template_path = ROOT / 'infra/aws/cloudformation/hico-thermal.yml'
    data = yaml.load(template_path.read_text(encoding='utf-8'), Loader=CloudFormationLoader)
    assert data['Resources']['ArtifactBucket']['Type'] == 'AWS::S3::Bucket'
    assert data['Resources']['CodeBuildProject']['Type'] == 'AWS::CodeBuild::Project'
    assert data['Resources']['GitHubActionsRole']['Type'] == 'AWS::IAM::Role'
    lifecycle = data['Resources']['ArtifactBucket']['Properties']['LifecycleConfiguration']['Rules']
    assert any(rule.get('Id') == 'AbortIncompleteUploads' for rule in lifecycle)
    assert data['Resources']['CodeBuildProject']['Properties']['Source']['Type'] == 'NO_SOURCE'
    assert data['Resources']['CodeBuildProject']['Properties']['BuildBatchConfig']['Restrictions']['MaximumBuildsAllowed'] == 'BatchMaximumBuilds'
    proc = subprocess.run(['bash', '-n', str(ROOT / 'infra/aws/deploy.sh')], check=False)
    assert proc.returncode == 0
    print('AWS infrastructure template and deploy script checks: PASS')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
