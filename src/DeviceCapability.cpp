#include "DeviceCapability.hpp"

#include <utility>

DeviceCapability::DeviceCapability(
        String _type,
        String _interface,
        String _version,
        std::list<String> _properties) : type(std::move(_type)), interface(std::move(_interface)),
                                         version(std::move(_version)),
                                         properties(std::move(_properties)) {}

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
