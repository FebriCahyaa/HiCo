# Vendored: orlp/ed25519

Unmodified copy of the public-domain-style (zlib licensed) Ed25519 reference
implementation by Orson Peters.

- Source: https://github.com/orlp/ed25519
- Commit: b1f19fab4aebe607805620d25a5e42566ce46a0e (2022-10-03)
- License: zlib (see `LICENSE.txt` in this directory — must stay with the code)

Used by HiCo's integrity/signing layer (`jni/include/Ed25519.hpp`,
`jni/src/Ed25519.cpp`, `tools/hico_sign`) to sign releases and verify them,
both at install time and while `hicod` runs. Do not hand-edit these files —
if a fix is needed, pull a new copy from upstream and update the commit
above.
