#ifndef DEVICE_INFO_HPP
#define DEVICE_INFO_HPP

#include <ArduinoJson.h>
#include <list>
#include "Alexa.hpp"
#include "DeviceCapability.hpp"

class DeviceInfo {
  String endpointId;
  String friendlyName;
  String description;
  String manufacturerName;
  std::list<String> displayCategories;
  std::list<DeviceCapability> deviceCapabilities;
  void prepareCapabilities(JsonArray);
  static const unsigned int JSON_BUFFER_SIZE;

 public:
  DeviceInfo(String, String, String, String, std::list<String>, std::list<DeviceCapability>);
  String getDiscoveryInfo();
  std::list<DeviceCapability> getDeviceCapabilities();
};

#endif
