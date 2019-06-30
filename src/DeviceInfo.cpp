#include "DeviceInfo.hpp"

const unsigned int DeviceInfo::JSON_BUFFER_SIZE = 3072;

DeviceInfo::DeviceInfo(String _endpointId,
                       String _friendlyName,
                       String _description,
                       String _manufacturerName,
                       std::list<String> _displayCategories,
                       std::list<DeviceCapability> _deviceCapabilities) : endpointId(_endpointId), friendlyName(_friendlyName), description(_description), manufacturerName(_manufacturerName), displayCategories(_displayCategories), deviceCapabilities(_deviceCapabilities) {
                         deviceConfiguration = new DeviceConfiguration();
                       }

String DeviceInfo::getDiscoveryInfo() {
  String output = "";
  StaticJsonDocument<JSON_BUFFER_SIZE> jsonBuffer;
  jsonBuffer["endpointId"] = endpointId;
  jsonBuffer["friendlyName"] = friendlyName;
  jsonBuffer["description"] = description;
  jsonBuffer["manufacturerName"] = manufacturerName;
  jsonBuffer.createNestedObject("cookie");

  JsonArray categories = jsonBuffer.createNestedArray("displayCategories");
  for (auto category : displayCategories) {
    categories.add(category);
  }

  prepareCapabilities(jsonBuffer.createNestedArray("capabilities"));
  serializeJsonPretty(jsonBuffer, output);

  return output;
}

void DeviceInfo::prepareCapabilities(JsonArray capabilities) {
  for (auto capability : deviceCapabilities) {
    JsonObject nestedCapability = capabilities.createNestedObject();
    nestedCapability["type"] = capability.getType();
    nestedCapability["interface"] = capability.getInterface();
    nestedCapability["version"] = capability.getVersion();

    std::list<String> properties = capability.getProperties();
    if (!properties.empty()) {
      JsonObject supportedProperty = nestedCapability.createNestedObject("properties");
      JsonArray supportedProperties = supportedProperty.createNestedArray("supported");

      for (auto property : properties) {
        JsonObject nestedProperty = supportedProperties.createNestedObject();
        nestedProperty["name"] = property;
      }

      supportedProperty["proactivelyReported"] = true;
      supportedProperty["retrievable"] = true;
    }

    if (Alexa::Interface::THERMOSTAT.equalsIgnoreCase(capability.getInterface())) {
      JsonObject configuration = nestedCapability.createNestedObject("configuration");
      configuration["supportsScheduling"] = deviceConfiguration->supportsScheduling();
      JsonArray supportedModes = configuration.createNestedArray("supportedModes");
      
      for (auto mode : deviceConfiguration->getSupportedModes()) {
        supportedModes.add(mode);
      }
    }
  }
}

std::list<DeviceCapability> DeviceInfo::getDeviceCapabilities() {
  return deviceCapabilities;
}

DeviceConfiguration* DeviceInfo::getDeviceConfiguration() {
  return deviceConfiguration;
}

DeviceInfo* DeviceInfo::withDeviceConfiguration(DeviceConfiguration* _deviceConfiguration) {
  deviceConfiguration = _deviceConfiguration;
  return this;
}
