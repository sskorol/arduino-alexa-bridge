#ifndef ALEXA_HPP
#define ALEXA_HPP

#include <Arduino.h>
#include "DeviceCapability.hpp"

namespace Alexa {
static const String API_VERSION = "3";

class DeviceCapability powerCapability();
class DeviceCapability brightnessCapability();
class DeviceCapability alexaCapability();
class DeviceCapability healthCapability();
class DeviceCapability channelCapability();
class DeviceCapability inputSourceCapability();
class DeviceCapability speakerCapability();
class DeviceCapability playbackCapability();
class DeviceCapability playbackStateCapability();

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
  static const String PLAYBACK;
  static const String PLAYBACK_STATE;
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
  static const String PLAY;
  static const String PAUSE;
  static const String STOP;
  static const String START_OVER;
  static const String PREVIOUS;
  static const String NEXT;
  static const String REWIND;
  static const String FAST_FORWARD;
  static const String PLAYBACK_STATE;
  static const String PLAYING;
  static const String STOPPED;
  static const String PAUSED;
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
