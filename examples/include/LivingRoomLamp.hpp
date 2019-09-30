#ifndef LIVING_ROOM_LAMP_HPP
#define LIVING_ROOM_LAMP_HPP

#include "DeviceInfo.hpp"
#include "Lamp.hpp"
#include "AlexaBridge.hpp"

class LivingRoomLamp : public Lamp, public AlexaBridge {
    static const unsigned int UNCERTAINTY_MS;
    static const unsigned int JSON_BUFFER_SIZE;
    static const unsigned int RC_SWITCH_PROTOCOL;
    static const unsigned int RC_SWITCH_LENGTH;
    static const unsigned long TURN_ON_CODE;
    static const unsigned long TURN_OFF_CODE;
    DeviceInfo *deviceInfo;
    bool _isPaused;

public:
    explicit LobbyLamp1(uint8_t);

    void turnOn();

    void turnOff();

    void setPowerState(bool);

    bool isManuallyPressed(unsigned long);

    void resetManualState();

    bool isPaused();

    String getDeviceInfo() override;

    String getStateReport() override;
};

#endif
