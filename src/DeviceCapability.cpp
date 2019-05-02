#include "DeviceCapability.hpp"

DeviceCapability::DeviceCapability(
    String _type,
    String _interface,
    String _version,
    std::list<String> _properties) : type(_type), interface(_interface), version(_version), properties(_properties) {}

String DeviceCapability::getType() {
    return type;
}

String DeviceCapability::getInterface() {
    return interface;
}

String DeviceCapability::getVersion() {
    return version;
}

std::list<String> DeviceCapability::getProperties() {
    return properties;
}
