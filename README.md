# LoongSocket LS-W1-1119-38P-S3

Public SDK and hardware documentation package for the LoongSocket
`LS-W1-1119-38P-S3` platform.

This repository contains the customer-facing API surface:

- Public headers in `include/ls/`.
- API documentation in `docs/API/`.
- Hardware documentation and schematics in `docs/hardware/`.
- Example code in `examples/`.
- Reserved `lib/` folder for precompiled libraries.

This SDK does not contain private firmware sources, factory tools, license keys or production scripts.

## Module

- Product code: `LS-W1-1119-38P-S3`
- Module variant: `ESP32-S3-WROOM-1U-N16R8`
- MCU family: ESP32-S3
- Flash: 16 MB
- PSRAM: 8 MB
- Target ESP-IDF: 5.5.4

## API boundary

- `ls_api.h` is the common module API for LoongSocket identity, health and
  module services.
- Product APIs built on top of this module must keep their own prefix. For
  example, AI-PLC Core uses `aiplc_core_api.h` for PLC runtime features.

## Current status

Prototype SDK structure with public headers and Markdown API documentation.
Precompiled `.a` libraries will be added when the private firmware API boundary
is frozen.

## Folders

| Path | Content |
| --- | --- |
| `include/ls/` | Public LS API headers. |
| `lib/` | Precompiled libraries, added by release packaging. |
| `examples/` | Minimal usage examples. |
| `docs/API/` | API reference in Markdown, Word and PDF. |
| `docs/hardware/` | Public hardware notes and pinout material. |
| `docs/release/` | Changelog and versioning notes. |
| `tools/` | Public helper tools when needed. |

## Versioning

SDK versions follow semantic versioning:

```text
MAJOR.MINOR.PATCH
```

The SDK version must match the compatible private firmware/API release.
