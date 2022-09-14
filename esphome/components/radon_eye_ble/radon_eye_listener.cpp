#include "radon_eye_listener.h"
#include "esphome/core/log.h"

#ifdef USE_ESP32

namespace esphome {
namespace radon_eye_ble {

static const char *const TAG = "radon_eye_ble";

bool RadonEyeListener::parse_device(const esp32_ble_tracker::ESPBTDevice &device) {
  if (not device.get_name().empty()) {
    if (device.get_name().rfind("FR:R20:SN", 0) == 0) {
      // this is an older firmware RD200
      ESP_LOGD(TAG, "Found Radon Eye RD200 Device (V0) Name: %s (MAC: %s)", device.get_name().c_str(),
               device.address_str().c_str());
    } else if (device.get_name().rfind("FR:RU", 0) == 0) {
      // this is a newer firmware RD200
      ESP_LOGD(TAG, "Found Radon Eye RD200 Device (V1) Name: %s (MAC: %s)", device.get_name().c_str(),
               device.address_str().c_str());
    }
  }
  return false;
}

}  // namespace radon_eye_ble
}  // namespace esphome

#endif
