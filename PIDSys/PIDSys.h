#ifndef PIDSYS_H
#define PIDSYS_H

#include "TCRT.h"
#include "CommonDefs.h"

/*
This class is for calculating PID error as two PWM outputs. This is unfiltered output, btw, so we will have to pass this through a speed regulator that takes into account current wheel speed and other buggy params.
The PID output value assume that the error is RIGHT - LEFT (looking from buggy top view), so a situation where right > left would be when the buggy is headed left and vice versa.
*/
class PIDSys
{
private:
    float error[3];
    float errorOuter[3];
    float output;
    float leftSpeed, rightSpeed;
    float A0, A1, A2;
    TCRT *S1;
    TCRT *S2;
    TCRT *S4;
    TCRT *S5;

public:
    PIDSys(TCRT *s1, TCRT *s2, TCRT *s4, TCRT *s5);
    void reset();
    void calculatePID(bool toggleAggressive);
    float getLeftSpeed() const;
    float getRightSpeed() const;
    float getOutput() const;

private:
    void outputPWM(); // private because internal utility function
};

#endif // PIDSYS_H
