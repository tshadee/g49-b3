#include "encoder.h"
#include "CommonDefs.h"

Encoder::Encoder(QEI *q) : encode(q) { resetAllValues(); };

// Encoder::Encoder(PinName channel1, PinName channel2): encode(channel1,channel2,NC,CPR,QEI::X4_ENCODING), count(0), countPrev(0), distance(0.0f), speed(0.0f){ resetAllValues(); };
void Encoder::updateValues(void)
{
    countPrev = count;
    count -= encode->getPulses();
    distance = count * WHEEL_DIAMETER * PI / CPR;
    // distance += static_cast<float>(encode->getRevolutions()*WHEEL_DIAMETER*PI);
    countBuffer = count - countPrev; // difference in count
    speed = ((static_cast<float>(countBuffer) / CPR) * SYS_OUTPUT_RATE) * WHEEL_DIAMETER * PI;
    encode->reset();
};

void Encoder::resetAllValues(void)
{
    encode->reset();
    distance = speed = 0.0f;
    count = countPrev = 0;
};

void Encoder::resetDistance(void)
{
    encode->reset();
    distance = count = 0.0f;
};

float Encoder::getDist(void) { return distance; }; // returns distance from last reset() call
float Encoder::getSpeed(void) { return speed; };   // returns speed in m/s
int Encoder::getCount(void) { return count; };
