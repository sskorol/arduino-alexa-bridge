#include "DeviceConfiguration.hpp"

DeviceConfiguration::DeviceConfiguration(bool _isSchedulingSupported, std::list<String> _supportedModes) : isSchedulingSupported(_isSchedulingSupported), supportedModes(_supportedModes) {}

DeviceConfiguration::DeviceConfiguration() {
  isSchedulingSupported = false;
  supportedModes = {};
}

bool DeviceConfiguration::supportsScheduling() {
  return isSchedulingSupported;
}

std::list<String> DeviceConfiguration::getSupportedModes() {
  return supportedModes;
}
