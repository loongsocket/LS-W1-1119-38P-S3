# LS Common API

`ls_api` is the stable module-level entry point for the LoongSocket ESP32-S3
module. It belongs to the module, not to any specific product built with the
module.

Use this API when firmware needs module identity, memory information, reset
state, internal temperature, USB health or a single safe initialization point for
LoongSocket services.

AI-PLC Core shall consume this layer internally, but PLC-specific features remain
in `aiplc_core_api.h`.

## Layer Boundary

| Layer | Prefix | Owner | Examples |
| --- | --- | --- | --- |
| LoongSocket module | `ls_` | LS module firmware/SDK | module P/N, MAC, serial, flash, PSRAM, temperature, USB, MCP3208, GPIO/PWM primitives |
| AI-PLC Core product | `aiplc_` | PLC runtime/SDK | DI/DO, AI/AO, Modbus, MQTT, OPC UA, Lua, profiles, calibration, remote I/O |

Do not add PLC concepts such as Modbus maps, relay names, MQTT profiles or Lua
permissions to `ls_api`. Do not add raw module services such as USB ownership,
module UID generation or MCP3208 SPI pin details to `aiplc_core_api` unless they
are intentionally wrapped as PLC diagnostics.

## Header

```c
#include "ls_api.h"
```

SDK users normally include:

```c
#include "ls/ls_api.h"
```

## Version

```c
uint32_t ls_api_version(void);
const char *ls_api_version_string(void);
const char *ls_api_module_part_number(void);
```

Current API version: `0.2.0-alpha`.

## Initialization

```c
esp_err_t ls_api_init(void);
```

Initializes the safe common LoongSocket services:

1. `ls_bms`
2. `ls_usb`
3. `ls_mcp3208`
4. `ls_io`
5. `ls_storage`

The function records the result of every subsystem. If one subsystem fails, the
first failing error is returned and detailed subsystem results remain available
through `ls_api_get_status()`.

## Module Info

```c
esp_err_t ls_api_get_module_info(ls_api_module_info_t *info);
```

Returns stable manufacturing/module identity:

- module part number
- chip model
- MAC bytes and formatted MAC string
- short serial derived from MAC
- device UID derived from MAC
- detected flash bytes
- detected PSRAM bytes
- ADC channel count and ADC resolution
- module capability flags

## Runtime Status

```c
esp_err_t ls_api_get_status(ls_api_status_t *status);
```

Returns aggregated runtime status:

- initialization result and per-service results
- reset reason
- heap and minimum heap
- PSRAM bytes
- internal temperature, when available
- NVS boot-health state
- safe-mode recommendation
- USB ready/connected/recovery flags

## Temperature

```c
esp_err_t ls_api_read_internal_temperature_celsius(float *out_celsius);
```

This is a thin wrapper over the board-management temperature sensor. It is safe
for products to use for diagnostics and logs. It is not a calibrated ambient or
process temperature measurement.

## Reset Reason

```c
const char *ls_api_reset_reason_name(esp_reset_reason_t reason);
```

Returns a stable text name for ESP reset reasons.
