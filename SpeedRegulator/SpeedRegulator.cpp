#include "SpeedRegulator.h"
#include "CommonDefs.h"

speedRegulator::speedRegulator(Encoder *LWC, Encoder *RWC) : leftWheelEncoder(LWC), rightWheelEncoder(RWC)
{
    currentLeftPWM = currentRightPWM = DEFAULT_PWM;
    currentLeftSpeed = currentRightSpeed = 0.0f;
    targetLeftSpeed = targetRightSpeed = 0.0f;
};

void speedRegulator::updateTargetSpeed(float leftSpeed, float rightSpeed)
{
    targetLeftSpeed = leftSpeed;
    targetRightSpeed = rightSpeed;
    adjustPWMOutputOnSpeed();
};

void speedRegulator::adjustPWMOutputOnSpeed()
{
    leftWheelEncoder->updateValues();
    rightWheelEncoder->updateValues();
    currentLeftSpeed = leftWheelEncoder->getSpeed();
    currentRightSpeed = rightWheelEncoder->getSpeed();
    float leftSpeedDiff = targetLeftSpeed - currentLeftSpeed;
    float rightSpeedDiff = targetRightSpeed - currentRightSpeed;

    currentLeftPWM += leftSpeedDiff * EASING_FACTOR / SYS_OUTPUT_RATE;
    currentRightPWM += rightSpeedDiff * EASING_FACTOR / SYS_OUTPUT_RATE;

    //PWM clamping
    // currentLeftPWM = (currentLeftPWM < 0.02f) ? 0.0f : ((currentLeftPWM > 0.98f) ? 1.0f : currentLeftPWM);
    // currentRightPWM = (currentRightPWM < 0.02f) ? 0.0f : ((currentRightPWM > 0.98f) ? 1.0f : currentRightPWM);
};

float speedRegulator::getCurrentLeftPWM(void) { return currentLeftPWM; };
float speedRegulator::getCurrentRightPWM(void) { return currentRightPWM; };
