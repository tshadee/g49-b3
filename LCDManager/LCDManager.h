#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

#include "mbed.h"
#include "C12832.h"
#include "BatteryMonitor.h"
#include "TCRT.h"
#include "encoder.h"

// LCD display buffer. Pass string pointers to display in lines 1-3 on the LCD screen. Keep the strings under 23 bytes if possible
//  call toScreen with the appropriate arguments to push anything to the LCD display - refresh rate sensitive (dont go above 15 Hz)
class LCDManager
{
private:
    C12832 *lcd;

public:
    LCDManager(C12832 *c); // Constructor might not be necessary if no initialization is needed
    void toScreen(const char *line1, const char *line2, const char *line3);
    char *batteryMonitorBuffer(BatteryMonitor *Batt);
    char *encoderOutputTest(Encoder *leftWheel, Encoder *rightWheel);
    char *SVB1(TCRT *S3);
    char *SVB2(TCRT *S1, TCRT *S2, TCRT *S4, TCRT *S5);
    char *FloatOutput(float one, float two, float three);
    char *FloatOutput2(float one, float two, float three);
};

#endif // LCD_MANAGER_H
