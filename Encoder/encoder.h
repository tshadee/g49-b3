#ifndef ENCODER_H
#define ENCODER_H

#include "mbed.h"
#include "QEI.h"

/*
Records QEI inputs and returns speed and distance for wheel. Use getDist() and getSpeed().
*/

// forward declaration of QEI class
class QEI;

class Encoder
{
private:
    QEI *encode;
    int count, countPrev;
    float distance;
    float speed;
    int countBuffer;

public:
    Encoder(QEI *q);
    void updateValues(void);
    void resetAllValues(void);
    float getDist(void);  // returns distance from last reset() call
    float getSpeed(void); // returns speed in m/s
    int getCount(void);   // returns count of encoder
    void resetDistance(void);
};

#endif
