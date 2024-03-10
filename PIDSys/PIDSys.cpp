#include "PIDSys.h"

PIDSys::PIDSys(TCRT *s1, TCRT *s2, TCRT *s4, TCRT *s5)
    : S1(s1), S2(s2), S4(s4), S5(s5), output(0), leftSpeed(0.0f), rightSpeed(0.0f)
{
    // A0 = GAIN_PROPORTIONAL + GAIN_INTEGRAL / SYS_OUTPUT_RATE + GAIN_DERIVATIVE * SYS_OUTPUT_RATE;
    // A1 = -GAIN_PROPORTIONAL - 2 * GAIN_DERIVATIVE * SYS_OUTPUT_RATE;
    // A2 = GAIN_DERIVATIVE * SYS_OUTPUT_RATE;
    reset();
};

void PIDSys::reset()
{
    error[2] = error[1] = error[0] = output = 0;
    leftSpeed = 0.0f;
    rightSpeed = 0.0f;
};

void PIDSys::calculatePID(bool toggleAggressive)
{
    error[2] = error[1];
    error[1] = error[0];
    error[0] = ((S5->getSensorVoltage(true)*3) + S4->getSensorVoltage(true) - S2->getSensorVoltage(true) - (S1->getSensorVoltage(true)*3));
    output = (((GAIN_PROPORTIONAL * error[0]) + (GAIN_DERIVATIVE * (error[0] - error[1])*SYS_OUTPUT_RATE) + (GAIN_INTEGRAL * (error[0]/2 + error[1]/2) / SYS_OUTPUT_RATE)) / GAIN_SCALE_DOWN);
    outputPWM();
};

void PIDSys::outputPWM()
{
    leftSpeed = BASE_SPEED + output;
    rightSpeed = BASE_SPEED - output;
};

float PIDSys::getLeftSpeed() const
{
    return leftSpeed;
};

float PIDSys::getRightSpeed() const
{
    return rightSpeed;
};

float PIDSys::getOutput() const
{
    return output;
};
