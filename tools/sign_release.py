#!/usr/bin/env python3
"""Build and sign a release's integrity manifest (jni/include/Integrity.hpp).

Run against the staged module directory compile_zip.sh already builds (before
it is zipped): hashes the files that matter for tamper detection, generates a
fresh WebUI aggregate manifest, signs the whole thing with hico_sign, and
writes <stage>/integrity.manifest — which then ships inside the zip like any
other module file and is checked by `hicod` at every start and periodically
while it runs.

See docs/INTEGRITY.md for the full design, docs/INTEGRITY.md#releasing for
the release-time steps that call this.

    python3 tools/sign_release.py --stage STAGE --version 1.4.0 \
        --hico-sign build/hico_sign --priv release_priv.hex

Signs with the public key already compiled into jni/include/IntegrityKey.hpp
(never a key guessed from --priv's filename), so a signed manifest can never
end up paired with a different key than the one the built hicod verifies
against. Without --priv, prints the manifest that *would* be signed (for
local inspection) and exits 1 — this script never signs with a placeholder
key, and it never invents one.
"""
from __future__ import annotations

import argparse
import datetime
import hashlib
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INTEGRITY_KEY_HEADER = ROOT / "jni" / "include" / "IntegrityKey.hpp"


def compiled_public_key() -> str:
    """The public key hicod is actually built with — the single source of truth, so a signed
    manifest can never end up paired with a different key than the one in the binary."""
    text = INTEGRITY_KEY_HEADER.read_text()
    m = re.search(r'HICO_INTEGRITY_PUBLIC_KEY_HEX\s+"([0-9a-f]{64})"', text)
    if not m:
        raise SystemExit(f"could not find HICO_INTEGRITY_PUBLIC_KEY_HEX in {INTEGRITY_KEY_HEADER}")
    return m.group(1)

# Files that matter for tamper detection: the binary itself, the scripts a root manager runs
# before hicod ever gets a say, and the untouched module.prop (hicod rewrites the live one's
# description at runtime — customize.sh already keeps module.prop.orig as the static snapshot,
# so that is what gets signed and what hicod compares itself against, never the live file).
SCRIPTS = ["service.sh", "action.sh", "customize.sh", "uninstall.sh", "verify.sh"]


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def collect_files(stage: Path) -> list[tuple[str, str]]:
    entries: list[tuple[str, str]] = []

    libs = stage / "libs"
    abis = sorted(p.name for p in libs.iterdir()) if libs.is_dir() else []
    if not abis:
        raise SystemExit(f"no libs/<abi>/hicod under {stage} — run this after ndk-build and staging")
    for abi in abis:
        binary = libs / abi / "hicod"
        if not binary.is_file():
            raise SystemExit(f"missing {binary}")
        entries.append(("system/bin/hicod", sha256_file(binary)))

    for name in SCRIPTS:
        path = stage / name
        if not path.is_file():
            raise SystemExit(f"missing {path}")
        entries.append((name, sha256_file(path)))

    module_prop = stage / "module.prop"
    if not module_prop.is_file():
        raise SystemExit(f"missing {module_prop}")
    entries.append(("module.prop.orig", sha256_file(module_prop)))

    # Fresh aggregate of the staged WebUI (never trust docs/integrity/webui.sha256 here: that
    # covers the checked-in source tree, this must match exactly what is in *this* zip).
    webroot = stage / "webroot"
    if not webroot.is_dir():
        raise SystemExit(f"missing {webroot}")
    webroot_manifest = stage / "webroot.sha256"
    subprocess.run(
        [sys.executable, str(ROOT / "tools" / "verify_webui.py"), "--webui", str(webroot),
         "--manifest", str(webroot_manifest), "--write"],
        check=True,
    )
    entries.append(("webroot.sha256", sha256_file(webroot_manifest)))

    return entries


def build_unsigned_manifest(version: str, entries: list[tuple[str, str]]) -> str:
    built_at = datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")
    lines = [
        "schema=hico.integrity-manifest.v1",
        f"version={version}",
        f"built_at={built_at}",
    ]
    # Sorted for a deterministic, diffable file; duplicate (path, hash) pairs collapse (a
    # "universal" build listing the same script once is harmless, listing it twice is noise).
    for path, digest in sorted(set(entries)):
        lines.append(f"file {digest} {path}")
    return "\n".join(lines) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stage", required=True, help="staged module directory (compile_zip.sh's $stage)")
    ap.add_argument("--version", required=True)
    ap.add_argument("--hico-sign", default="build/hico_sign", help="path to the hico_sign host binary")
    ap.add_argument("--priv", help="release private key hex file (never commit this)")
    ap.add_argument("--out", help="default: <stage>/integrity.manifest")
    args = ap.parse_args()

    stage = Path(args.stage)
    entries = collect_files(stage)
    unsigned = build_unsigned_manifest(args.version, entries)

    if not args.priv:
        print(unsigned, end="")
        print(f"\n({len(entries)} files; pass --priv to actually sign)", file=sys.stderr)
        return 1

    priv = Path(args.priv)
    if not priv.is_file():
        raise SystemExit(f"private key not found: {priv}")
    # Always the key actually compiled into this build's hicod (jni/include/IntegrityKey.hpp),
    # never a file sitting next to --priv: that guarantees the two can never quietly mismatch
    # (signing with a private key whose public half is not the one hicod verifies against would
    # produce a manifest no release of this build could ever pass).
    pub_hex = compiled_public_key()

    with tempfile.NamedTemporaryFile("w", suffix=".manifest", delete=False) as tmp:
        tmp.write(unsigned)
        tmp_path = Path(tmp.name)
    with tempfile.NamedTemporaryFile("w", suffix=".pub", delete=False) as tmp_pub:
        tmp_pub.write(pub_hex + "\n")
        pub_path = Path(tmp_pub.name)
    try:
        signature = subprocess.run(
            [args.hico_sign, "sign", str(tmp_path), str(priv), str(pub_path)],
            check=True, capture_output=True, text=True,
        ).stdout.strip()
    finally:
        tmp_path.unlink(missing_ok=True)
        pub_path.unlink(missing_ok=True)

    signed = unsigned + f"signature={signature}\n"
    out = Path(args.out) if args.out else stage / "integrity.manifest"
    out.write_text(signed)
    print(f"signed manifest written: {out} ({len(entries)} files)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
