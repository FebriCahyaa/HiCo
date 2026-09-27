# HiCo Universal Device + ROM + Thermal Source

The universal model separates **hardware identity**, **ROM identity**, and **thermal source provenance**.

```text
Device (hardware)
  ├── ROM references
  └── Thermal Source references

ROM
  └── Device references + Thermal Source references

Thermal Source
  ├── Device reference
  ├── ROM reference
  ├── repository + commit
  ├── repository role
  ├── source layer
  └── thermal formats
```

A device therefore exists once:

```text
xiaomi/garnet
```

and can be associated with:

```text
hyperos/16
lineageos/17
pixelos/17
crdroid/17
```

without duplicating the hardware record.

`database/schema/universal.v1.schema.json` is the machine-readable contract.

`tools/hico_universal.py` builds:

```text
database/universal/index.json
```

from the canonical `thermal-data/**/manifest.json` records plus the legacy `devices/*/*.prop` runtime table.

The universal index is a knowledge-layer index. It does **not** replace `devices/` runtime compatibility data yet.
That keeps this migration backward-compatible while allowing multi-OEM and multi-ROM collection to grow safely.
