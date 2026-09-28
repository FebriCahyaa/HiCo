/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

// Production release public key.
//
// The matching private key is NEVER stored in this repository. Signed releases use
// the GitHub Actions secret HICO_INTEGRITY_PRIVATE_KEY.
//
// Host-side CMake tests override this macro with their deterministic test key so the
// production key is never needed by the test suite.

#ifndef HICO_INTEGRITY_PUBLIC_KEY_HEX
#define HICO_INTEGRITY_PUBLIC_KEY_HEX "99b33175e39f03bff7eed24b22af43372cb248bf97f62244ab37a1c7744bed77"
#endif
