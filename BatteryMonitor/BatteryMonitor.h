#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include "mbed.h"
#include <cstdint>
// use the one-wire-pin PC_12
class BatteryMonitor
{
private:
    DigitalInOut *one_wire_pin;
    uint16_t VoltageReading;
    float Voltage;

public:
    BatteryMonitor(DigitalInOut *OWP);
    void pollBattery(void);
    float getBatteryVoltage(void);
};

#endif
