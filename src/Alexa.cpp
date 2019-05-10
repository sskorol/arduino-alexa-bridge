#include "Alexa.hpp"

using namespace Alexa;

const String Interface::DISCOVERY = "Alexa.Discovery";
const String Interface::POWER = "Alexa.PowerController";
const String Interface::ALEXA = "Alexa";
const String Interface::ENDPOINT_HEALTH = "Alexa.EndpointHealth";
const String Interface::AUTHORIZATION = "Alexa.Authorization";
const String Interface::BRIGHTNESS = "Alexa.BrightnessController";
const String Interface::CHANNEL = "Alexa.ChannelController";
const String Interface::SPEAKER = "Alexa.Speaker";
const String Interface::INPUT_SOURCE = "Alexa.InputController";
const String Interface::PLAYBACK = "Alexa.PlaybackController";
const String Interface::PLAYBACK_STATE = "Alexa.PlaybackStateReporter";

const String Property::POWER_STATE = "powerState";
const String Property::CONNECTIVITY = "connectivity";
const String Property::BRIGHTNESS = "brightness";
const String Property::CHANNEL = "channel";
const String Property::INPUT_SOURCE = "input";
const String Property::VOLUME = "volume";
const String Property::MUTED = "muted";
const String Property::PLAY = "Play";
const String Property::PAUSE = "Pause";
const String Property::STOP = "Stop";
const String Property::START_OVER = "StartOver";
const String Property::PREVIOUS = "Previous";
const String Property::NEXT = "Next";
const String Property::REWIND = "Rewind";
const String Property::FAST_FORWARD = "FastForward";
const String Property::PLAYBACK_STATE = "playbackState";
const String Property::PLAYING = "PLAYING";
const String Property::STOPPED = "STOPPED";
const String Property::PAUSED = "PAUSED";

const String CapabilityType::ALEXA_INTERFACE = "AlexaInterface";

const String DisplayCategory::LIGHT = "LIGHT";
const String DisplayCategory::THERMOSTAT = "THERMOSTAT";
const String DisplayCategory::OTHER = "OTHER";
const String DisplayCategory::SMARTLOCK = "SMARTLOCK";
const String DisplayCategory::SCENE_TRIGGER = "SCENE_TRIGGER";
const String DisplayCategory::ACTIVITY_TRIGGER = "ACTIVITY_TRIGGER";
const String DisplayCategory::CAMERA = "CAMERA";
const String DisplayCategory::SWITCH = "SWITCH";
const String DisplayCategory::TV = "TV";

const String HeaderName::TURN_ON = "TurnOn";
const String HeaderName::TURN_OFF = "TurnOff";
const String HeaderName::ADJUST_BRIGHTNESS = "AdjustBrightness";
const String HeaderName::SET_BRIGHTNESS = "SetBrightness";
const String HeaderName::ADJUST_VOLUME = "AdjustVolume";
const String HeaderName::SET_VOLUME = "SetVolume";
const String HeaderName::SET_MUTE = "SetMute";
const String HeaderName::CHANGE_CHANNEL = "ChangeChannel";
const String HeaderName::SKIP_CHANNELS = "SkipChannels";

DeviceCapability Alexa::powerCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::POWER,
      Alexa::API_VERSION,
      {Property::POWER_STATE});
}

DeviceCapability Alexa::brightnessCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::BRIGHTNESS,
      Alexa::API_VERSION,
      {Property::BRIGHTNESS});
}

DeviceCapability Alexa::alexaCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::ALEXA,
      Alexa::API_VERSION,
      {});
}

DeviceCapability Alexa::healthCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::ENDPOINT_HEALTH,
      Alexa::API_VERSION,
      {Property::CONNECTIVITY});
}

DeviceCapability Alexa::channelCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::CHANNEL,
      Alexa::API_VERSION,
      {Property::CHANNEL});
}

DeviceCapability Alexa::inputSourceCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::INPUT_SOURCE,
      Alexa::API_VERSION,
      {Property::INPUT_SOURCE});
}

DeviceCapability Alexa::speakerCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::SPEAKER,
      Alexa::API_VERSION,
      {Property::VOLUME, Property::MUTED});
}

DeviceCapability Alexa::playbackCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::PLAYBACK,
      Alexa::API_VERSION,
      {Property::PLAY, Property::PAUSE, Property::PREVIOUS, Property::REWIND, Property::START_OVER, Property::STOP, Property::FAST_FORWARD, Property::NEXT});
}

DeviceCapability Alexa::playbackStateCapability() {
  return DeviceCapability(
      CapabilityType::ALEXA_INTERFACE,
      Interface::PLAYBACK_STATE,
      Alexa::API_VERSION,
      {Property::PLAYBACK_STATE});
}
