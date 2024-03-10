#ifndef TCRT_H
#define TCRT_H

#include "mbed.h"
#include <cstdint>
#include "CommonDefs.h"

// TCRT class. Creates an object for individual sensors on the sensor array with rolling average (size 5) built in.
// Provide the Pin (ADC) for the sensor and the voltage levels expected (if you want to scale to voltage instead of from 0.0 - 1.0)
// Use getSensorVoltage() to get value of voltage (rolled average).
class TCRT
{
private:
    AnalogIn sensorPin;
    DigitalOut DarlingtonPin;
    float VDD, senseNorm;
    float senseNormRolled[SENSOR_BUFFER];
    uint32_t rIndex;
    static TCRT *sensors[SENSOR_AMOUNT]; // operating with one ticker, so we must have a pointer to all the TCRT objects (to be used for function callback)
    static int sensorCount;              // to keep count of the sensors
public:
    TCRT(PinName Pin, PinName DarlingPin, float v);
    void turnSensorOn(void);
    void turnSensorOff(void);
    void rollingPollAverage();
    // runs through all the polling once called. This is for synchronous polling between sensors since static is shared between all objects derived from TCRT
    static void pollSensors(void);
    float getSensorVoltage(bool Volt = false);
};

#endif
