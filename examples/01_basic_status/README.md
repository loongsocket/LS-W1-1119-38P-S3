# 01 Basic Status

Minimal example showing the recommended LoongSocket module entry point.

Use `ls_api` when an application needs module identity, memory, reset state,
internal temperature or a safe one-call initialization of the common module
services.

This folder is a placeholder until the first precompiled SDK library release is
generated.

Expected APIs:

- `ls_api_init()`
- `ls_api_get_module_info()`
- `ls_api_get_status()`
- `ls_api_read_internal_temperature_celsius()`

Lower-level APIs such as `ls_bms_get_status()` and `ls_usb_get_status()` remain
available for advanced firmware that needs direct control.
