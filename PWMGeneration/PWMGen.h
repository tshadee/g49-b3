#ifndef PWMGEN_H
#define PWMGEN_h

#include "mbed.h"

class PWMGen
{
private:
    PwmOut PWM_LEFT, PWM_RIGHT;
    DigitalOut MDBEnable, BPE1, BPE2;

public:
    PWMGen(PinName leftPWMPin, PinName rightPWMPin, PinName MDBE, PinName Bipolar1E, PinName Bipolar2E);
    void reset();
    void begin();
    void setPWMDuty(float leftPWM, float rightPWM);
};

#endif
