#ifndef DEVICE_CONFIGURATION_HPP
#define DEVICE_CONFIGURATION_HPP

#include <Arduino.h>
#include <list>

class DeviceConfiguration {
  bool isSchedulingSupported;
  std::list<String> supportedModes;

 public:
  DeviceConfiguration();
  DeviceConfiguration(bool, std::list<String>);
  bool supportsScheduling();
  std::list<String> getSupportedModes();
};

#endif
