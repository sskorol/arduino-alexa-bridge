#ifndef ALEXA_HPP
#define ALEXA_HPP

#include <Arduino.h>

namespace Alexa {
static const String API_VERSION = "3";

class Interface {
 public:
  static const String DISCOVERY;
  static const String POWER;
  static const String ALEXA;
  static const String ENDPOINT_HEALTH;
  static const String AUTHORIZATION;
  static const String BRIGHTNESS;
  static const String CHANNEL;
  static const String SPEAKER;
  static const String INPUT_SOURCE;
};

class Property {
 public:
  static const String POWER_STATE;
  static const String CONNECTIVITY;
  static const String BRIGHTNESS;
  static const String CHANNEL;
  static const String INPUT_SOURCE;
  static const String VOLUME;
  static const String MUTED;
};

class CapabilityType {
 public:
  static const String ALEXA_INTERFACE;
};

class DisplayCategory {
 public:
  static const String LIGHT;
  static const String THERMOSTAT;
  static const String OTHER;
  static const String SMARTLOCK;
  static const String SCENE_TRIGGER;
  static const String ACTIVITY_TRIGGER;
  static const String CAMERA;
  static const String SWITCH;
  static const String TV;
};
}  // namespace Alexa

#endif
