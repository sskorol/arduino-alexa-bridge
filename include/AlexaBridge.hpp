#ifndef ALEXA_BRIDGE_HPP
#define ALEXA_BRIDGE_HPP

#include <Arduino.h>

class AlexaBridge {
 public:
  virtual ~AlexaBridge() {}
  virtual String getDeviceInfo() = 0;
  virtual String getStateReport() = 0;
};

#endif
