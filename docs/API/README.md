# LoongSocket LS-W1 S3 N16R8 API

This folder documents the public SDK API used by the `FW-LS-W1-S3-N16R8` module.

## Module

- Module P/N: `LS-W1-1119-38P-S3U-N16R8`
- MCU: ESP32-S3
- Flash: 16 MB
- PSRAM: 8 MB
- ADC: MCP3208, 8 channels, 12 bit, 2500 mV reference
- IDF: 5.5.4

## Components

| Component | Header | Purpose |
| --- | --- | --- |
| Common API | `ls_api.h` | Stable module entry point: version, identity, memory, temperature, reset state and safe service initialization |
| BMS | `ls_bms.h` | Board identity, reset reason, memory and safe-mode status |
| USB | `ls_usb.h` | Native USB Serial/JTAG status and recovery |
| Storage | `ls_storage.h` | NVS-backed storage with write-on-change |
| MCP3208 | `ls_mcp3208.h` | External ADC acquisition, filtering, calibration and diagnostics |
| I/O | `ls_io.h` | GPIO, PWM and board reserved-pin protection |
| Board Test | `ls_board_test.h` | Production/demo helpers for PWM, square-wave and ADC PASS/NO PASS |

## Recommended Entry Point

```cpp
#include "ls/ls_api.h"

ls_api_init();
```

Use lower-level headers only when the application needs direct peripheral access.

## Documentation Files

- `LS_COMMON_API.md`
- `LS_BMS_API.md`
- `LS_USB_API.md`
- `LS_STORAGE_API.md`
- `LS_MCP3208_API.md`
- `LS_IO_API.md`
- `LS_BOARD_TEST_API.md`
- `LS_API_STATUS.md`
