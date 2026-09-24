#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"
#include "esp_system.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LS_API_VERSION_MAJOR 0u
#define LS_API_VERSION_MINOR 2u
#define LS_API_VERSION_PATCH 0u
#define LS_API_VERSION_STRING "0.2.0-alpha"

#define LS_API_MODULE_PART_NUMBER "LS-W1-1119-38P-S3U-N16R8"
#define LS_API_MODULE_PART_NUMBER_MAX_LENGTH 32u
#define LS_API_CHIP_MODEL_MAX_LENGTH 24u
#define LS_API_MAC_STRING_SIZE 18u
#define LS_API_SERIAL_SIZE 5u
#define LS_API_DEVICE_UID_SIZE 16u
#define LS_API_ADC_CHANNEL_COUNT 8u
#define LS_API_ADC_RESOLUTION_BITS 12u
#define LS_API_FLASH_BYTES (16u * 1024u * 1024u)
#define LS_API_PSRAM_BYTES (8u * 1024u * 1024u)

#define LS_API_CAPABILITY_BMS            (1u << 0u)
#define LS_API_CAPABILITY_USB_SERIAL_JTAG (1u << 1u)
#define LS_API_CAPABILITY_NVS_STORAGE    (1u << 2u)
#define LS_API_CAPABILITY_MCP3208_ADC    (1u << 3u)
#define LS_API_CAPABILITY_GPIO_PWM       (1u << 4u)
#define LS_API_CAPABILITY_BOARD_TEST     (1u << 5u)

typedef struct {
    char module_part_number[LS_API_MODULE_PART_NUMBER_MAX_LENGTH];
    char chip_model[LS_API_CHIP_MODEL_MAX_LENGTH];
    uint8_t mac[6];
    char mac_string[LS_API_MAC_STRING_SIZE];
    char serial[LS_API_SERIAL_SIZE];
    char device_uid[LS_API_DEVICE_UID_SIZE];
    uint32_t flash_bytes;
    uint32_t psram_bytes;
    uint8_t adc_channels;
    uint8_t adc_resolution_bits;
    uint32_t capability_flags;
} ls_api_module_info_t;

typedef struct {
    bool initialized;
    esp_err_t init_result;
    esp_err_t bms_result;
    esp_err_t usb_result;
    esp_err_t adc_result;
    esp_err_t io_result;
    esp_err_t storage_result;
    bool internal_temperature_valid;
    int32_t internal_temperature_milli_celsius;
    esp_reset_reason_t reset_reason;
    uint32_t free_heap_bytes;
    uint32_t minimum_free_heap_bytes;
    uint32_t psram_bytes;
    bool nvs_ready;
    bool safe_mode_recommended;
    uint8_t boot_failure_count;
    bool usb_ready;
    bool usb_connected;
    bool usb_recovery_available;
} ls_api_status_t;

uint32_t ls_api_version(void);
const char *ls_api_version_string(void);
const char *ls_api_module_part_number(void);
esp_err_t ls_api_init(void);
esp_err_t ls_api_get_module_info(ls_api_module_info_t *info);
esp_err_t ls_api_get_status(ls_api_status_t *status);
esp_err_t ls_api_read_internal_temperature_celsius(float *out_celsius);
const char *ls_api_reset_reason_name(esp_reset_reason_t reason);

#ifdef __cplusplus
}
#endif
