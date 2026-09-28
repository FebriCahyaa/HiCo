# Integrity and tamper detection

This is the honest version of what HiCo's anti-tampering actually does, and — just as
important — what it cannot do. `hicod` runs as root, on a device its owner has root on: nothing
running at the same privilege level as the thing you are trying to protect can ever be made
un-defeatable by someone with the time and skill to work at that level. Client-side integrity
checks on a rooted device raise the cost and the risk of tampering, and make a compromised build
detectable and revocable after the fact. They do not, and cannot, make tampering impossible.

With that said: this is what actually exists, and the reasoning behind each piece.

## The three layers

### 1. Signed release manifest (authenticity, not just integrity)

Every release has always shipped a `.sha256` next to each file, checked by `module/verify.sh` at
flash time. That only ever proved the zip was not *corrupted* — anyone who edited a file could
regenerate its own `.sha256` and pass the same check, because there was no key involved.

`integrity.manifest` (built by `tools/sign_release.py`, verified by `jni/include/Integrity.hpp`)
replaces that with an actual signature:

- An Ed25519 keypair is generated once, offline, with `hico_sign genkey` (`tools/hico_sign_main.cpp`,
  on top of the vendored `jni/src/vendor/ed25519/` — see its `NOTICE.md`). The private key never
  goes in this repository; it lives as the `HICO_INTEGRITY_PRIVATE_KEY` GitHub Actions secret,
  used only by `release.yml`.
- The public key is compiled into `hicod` itself, in `jni/include/IntegrityKey.hpp`. Public keys
  are not secret — shipping it in the binary is the point of asymmetric signing.
- At release time, `tools/sign_release.py` hashes (SHA-256, `jni/src/vendor/sha256/`) the files
  that matter — `system/bin/hicod` itself, every install/service script, the untouched
  `module.prop.orig`, and an aggregate hash of the shipped WebUI (`webroot.sha256`) — and signs
  the list with the release private key.
- `hicod` verifies that signature against its own embedded public key at every start, and again
  every 30 minutes while it runs. A file that does not match what was signed, or is missing, or a
  signature that does not verify at all (a repackaged zip, an edited manifest, a manifest signed
  with a different key) blocks every thermal unlock until the module is reinstalled from an
  official release — never destructively, always by falling back to stock thermal.
- **A build that ships with no manifest at all (an older release, or one built without the
  signing secret configured) is *not* treated as tampered.** Ordinary CI builds never carry the
  private key and never will; only `release.yml`'s real releases do. Treating "missing" the same
  as "failed" would make an unsigned CI build indistinguishable from a compromised one, which
  helps no one.

Check it yourself: `hicod integrity` (or `--json`), independent of whether the daemon is running.
The WebUI's Monitor page shows the same thing.

**What this does not cover**: a new file simply *added* under `webroot/` after install, without
touching `webroot.sha256`, is invisible to the runtime check (it only re-hashes that one small
index file, not the whole tree, to avoid a recursive directory walk on-device having to match
`tools/verify_webui.py`'s Python implementation byte-for-byte — a mismatch there would be a false
positive for every user, which is worse than the gap it would close). Flash-time `verify.sh`
still covers every file present in the original zip; only files added post-install, that never
touch `webroot.sha256`, sit in this gap.

### 2. Runtime self-check

Beyond the signed-file check above, `hicod` also reads two cheap, best-effort signals every time
it re-verifies (`integrity::runtime_signals()`):

- `TracerPid` in `/proc/self/status` — non-zero means something has attached via `ptrace` (a
  debugger, `strace`, or a hooking tool that uses the same mechanism).
- A short, specific list of hook/injection library names (Frida's agent and gadget, `linjector`,
  ...) in `/proc/self/maps`.

**These are logged and shown in `hicod status` / `hicod integrity`, but never by themselves cause
a fail-safe.** Both have too many legitimate explanations — the author debugging a user's report,
another tool on the device that happens to `ptrace`, a coincidental library name — for a false
positive here to be an acceptable cost. The signed-manifest check above is the one signal strong
enough to act on unilaterally, because it cannot have an innocent explanation: bytes either match
what was signed or they do not.

### 3. Revocation list (a kill switch for a compromised build, after release)

The first two layers protect against *this device's copy* being edited. They cannot catch the
case where the build itself — signed with the real key, self-consistent, passes every check above
— turns out to be the problem: a leaked signing key, a build published by mistake, or someone
redistributing a cracked copy with its own still-internally-consistent manifest.

`docs/integrity/revoked.txt` in *this* repository is a small, plain-text, **unsigned** list of
`system/bin/hicod` hashes the author has published as compromised. `hicod` fetches it over HTTPS
from `raw.githubusercontent.com` (`integrity::fetch_revocation_list()`) at most once every 24
hours, and — only once a fetch has *not* found its own hash on it — treats a match as
equivalent to a failed manifest: fail-safe to stock, logged, notified, shown in status. Once
found revoked, that verdict is sticky for the life of the process (it does not un-revoke itself
just because the next 30-minute local recheck, which knows nothing about revocation, ran again).

It is deliberately **not** signed the way the release manifest is: it travels over TLS, and only
this repository's own write access can change it — no different, trust-wise, from `update.json`,
which every root manager already fetches the same way as part of normal update checking. This is
not phone-home telemetry: the request is a plain, anonymous `GET`, no device identifier, no
payload, nothing sent that fetching the URL in a browser would not already reveal. Toggle it with
`hicod config set check_revocation 0`.

**This is best-effort by design, not a gate anything has to pass.** `fetch_revocation_list()` only
tries `/system/bin/curl` or `/system/bin/wget` / `/system/xbin/wget`, in that order, and gives up
immediately if none exists — most stock ROMs have neither. When it does run, it is hard-bounded
(default 5 s, enforced in the parent process with `poll()` and a `SIGKILL` if the deadline passes,
not trusted to an external `timeout` binary that may not exist either) so a hung or slow network
can never stall thermal management. Anything short of a clean, timely response — no tool, no
network, a timeout, a non-200 status — is treated exactly like "nothing revoked."

## Releasing a signed build

```
# Once, offline. Keep priv.hex out of git — store it as the GitHub Actions
# secret HICO_INTEGRITY_PRIVATE_KEY, and nowhere else.
cmake -S . -B build && cmake --build build --target hico_sign
build/hico_sign genkey priv.hex pub.hex
```

Paste `pub.hex`'s contents into `HICO_INTEGRITY_PUBLIC_KEY_HEX` in
`jni/include/IntegrityKey.hpp` and commit that (it is public). `release.yml` reads the
`HICO_INTEGRITY_PRIVATE_KEY` secret and calls `tools/sign_release.py` for you; an ordinary CI
build (`build.yml`) never has that secret and ships unsigned, which is expected. See
`tools/sign_release.py`'s own docstring for the manual command.

If the private key is ever committed or leaked: treat every signature it ever made as
compromised. Generate a new keypair, update `IntegrityKey.hpp`, and — this is what layer 3 is
for — publish the old build's hash (or every hash it ever signed, if that is not known precisely)
to `docs/integrity/revoked.txt` so installs already in the wild find out.

## What this is not

It is not DRM, and it will not stop someone who genuinely wants to read or modify `hicod` on their
own device — root means they can always attach a debugger to their own root process, patch the
binary on disk, or run a kernel that lies to userspace about all of the above. What it does is
close the cheapest, most casual path (editing a file and moving on) and turn a wider compromise
(a leaked key, a redistributed cracked copy) from silent into something the author can publish a
kill switch for. That is the realistic bar for anti-tampering on a device the end user controls,
stated plainly rather than oversold.
