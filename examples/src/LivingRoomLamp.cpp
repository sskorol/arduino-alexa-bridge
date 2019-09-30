#include "LivingRoomLamp.hpp"

using namespace Alexa;

const unsigned int LivingRoomLamp::UNCERTAINTY_MS = 1000;
const unsigned int LivingRoomLamp::JSON_BUFFER_SIZE = 1024;
const unsigned int LivingRoomLamp::RC_SWITCH_PROTOCOL = 1;
const unsigned int LivingRoomLamp::RC_SWITCH_LENGTH = 24;
const unsigned long LivingRoomLamp::TURN_ON_CODE = 400001;
const unsigned long LivingRoomLamp::TURN_OFF_CODE = 400002;

LivingRoomLamp::LivingRoomLamp(uint8_t transmitterPin) : Lamp(transmitterPin) {
    _isPaused = false;
    deviceInfo = new DeviceInfo("living_room_lamp", "light", "Living Room Lamp 1", "Home", {DisplayCategory::LIGHT},
                                {Alexa::powerCapability(), Alexa::alexaCapability(), Alexa::healthCapability()});
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

/*
  These 2 methods required for tracking manual state changes
*/
bool LivingRoomLamp::isManuallyPressed(unsigned long code) {
    if (!_isPaused && (code == TURN_ON_CODE || code == TURN_OFF_CODE)) {
        _isPaused = true;
        Lamp::setPowerState(!Lamp::isTurnedOn());
        return true;
    }
    return false;
}

void LivingRoomLamp::resetManualState() {
    _isPaused = false;
}

bool LivingRoomLamp::isPaused() {
    return _isPaused;
}

String LivingRoomLamp::getStateReport() {
    String output = "";
    StaticJsonDocument <JSON_BUFFER_SIZE> jsonBuffer;
    JsonArray outputProperties = jsonBuffer.createNestedArray();

    for (auto capability : deviceInfo->getDeviceCapabilities()) {
        for (const auto &property : capability.getProperties()) {
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
