#ifndef DEVICE_CAPABILITY_HPP
#define DEVICE_CAPABILITY_HPP

#include <Arduino.h>
#include <list>

class DeviceCapability {
    String type;
    String interface;
    String version;
    std::list<String> properties;

public:
    DeviceCapability(String, String, String, std::list<String>);

    String getType();

    String getInterface();

    String getVersion();

    std::list<String> getProperties();
};

#endif
