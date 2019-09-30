#include "DeviceConfiguration.hpp"

#include <utility>

DeviceConfiguration::DeviceConfiguration(bool _isSchedulingSupported, std::list<String> _supportedModes)
        : isSchedulingSupported(_isSchedulingSupported), supportedModes(std::move(_supportedModes)) {}

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
