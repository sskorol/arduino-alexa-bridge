#include "LivingRoomLamp.hpp"

using namespace Alexa;

const unsigned int LivingRoomLamp::UNCERTAINTY_MS = 1000;
const unsigned int LivingRoomLamp::JSON_BUFFER_SIZE = 1024;
const unsigned int LivingRoomLamp::RC_SWITCH_PROTOCOL = 1;
const unsigned int LivingRoomLamp::RC_SWITCH_LENGTH = 24;
const unsigned long LivingRoomLamp::TURN_ON_CODE = 400001;
const unsigned long LivingRoomLamp::TURN_OFF_CODE = 400002;

LivingRoomLamp::LivingRoomLamp(uint8_t pin) : Lamp(pin) {
  std::list<DeviceCapability> capabilities = initCapabilities();
  deviceInfo = new DeviceInfo("bedroom_lamp", "bedroom light", "Bedroom Lamp", "Home", {DisplayCategory::LIGHT}, capabilities);
}

std::list<DeviceCapability> LivingRoomLamp::initCapabilities() {
  DeviceCapability powerCapability = DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::POWER,
      API_VERSION,
      {Property::POWER_STATE});

  DeviceCapability alexaCapability = DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::ALEXA,
      API_VERSION,
      {});

  DeviceCapability healthCapability = DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::ENDPOINT_HEALTH,
      API_VERSION,
      {Property::CONNECTIVITY});

  return {powerCapability, alexaCapability, healthCapability};
}

void LivingRoomLamp::turnOn() {
  Lamp::switchProtocol(RC_SWITCH_PROTOCOL);
  Lamp::turnOn(TURN_ON_CODE, RC_SWITCH_LENGTH);
}

void LivingRoomLamp::turnOff() {
  Lamp::switchProtocol(RC_SWITCH_PROTOCOL);
  Lamp::turnOff(TURN_OFF_CODE, RC_SWITCH_LENGTH);
}

void LivingRoomLamp::setPowerState(bool state) {
  if (state) {
    turnOn();
  } else {
    turnOff();
  }
  Lamp::setPowerState(state);
}

String LivingRoomLamp::getDeviceInfo() {
  return deviceInfo->getDiscoveryInfo();
}

String LivingRoomLamp::getStateReport() {
  String output = "";
  StaticJsonDocument<JSON_BUFFER_SIZE> jsonBuffer;
  JsonArray outputProperties = jsonBuffer.createNestedArray();

  for (auto capability : deviceInfo->getDeviceCapabilities()) {
    for (auto property : capability.getProperties()) {
      JsonObject nestedProperty = outputProperties.createNestedObject();
      nestedProperty["namespace"] = capability.getInterface();
      nestedProperty["name"] = property;
      nestedProperty["timeOfSample"] = "";
      nestedProperty["uncertaintyInMilliseconds"] = UNCERTAINTY_MS;

      if (Property::CONNECTIVITY.equalsIgnoreCase(property)) {
        JsonObject value = nestedProperty.createNestedObject("value");
        value["value"] = "OK";
      } else if (Property::POWER_STATE.equalsIgnoreCase(property)) {
        nestedProperty["value"] = Lamp::isTurnedOn() ? "ON" : "OFF";
      }
    }
  }

  serializeJsonPretty(jsonBuffer, output);

  return output;
}
