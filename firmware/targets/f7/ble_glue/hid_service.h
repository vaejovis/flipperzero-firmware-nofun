#pragma once

#include <stdint.h>
#include <stdbool.h>

#define HID_SVC_REPORT_MAP_MAX_LEN (512)
#define HID_SVC_REPORT_MAX_LEN (255)
#define HID_SVC_REPORT_REF_LEN (2)
#define HID_SVC_INFO_LEN (4)
#define HID_SVC_CONTROL_POINT_LEN (1)

#define HID_SVC_INPUT_REPORT_COUNT (1)
#define HID_SVC_OUTPUT_REPORT_COUNT (0)
#define HID_SVC_FEATURE_REPORT_COUNT (0)
#define HID_SVC_REPORT_COUNT \
    (HID_SVC_INPUT_REPORT_COUNT + HID_SVC_OUTPUT_REPORT_COUNT + HID_SVC_FEATURE_REPORT_COUNT)

void hid_svc_start();

void hid_svc_stop();

bool hid_svc_is_started();

bool hid_svc_update_report_map(uint8_t* data, uint16_t len);

bool hid_svc_update_input_report(uint8_t* data, uint16_t len);

bool hid_svc_update_info(uint8_t* data, uint16_t len);
