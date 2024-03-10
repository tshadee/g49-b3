#include "LCDManager.h"
#include <cstdlib>

LCDManager::LCDManager(C12832 *c) : lcd(c){};

void LCDManager::toScreen(const char *line1, const char *line2, const char *line3)
{
    static char lastLine1[21] = "";
    static char lastLine2[21] = "";
    static char lastLine3[21] = "";
    if (strncmp(lastLine1, line1, 20) != 0)
    {
        strncpy(lastLine1, line1, 20);
        lastLine1[20] = '\0';
        lcd->locate(0, 0);
        lcd->printf(line1);
    };
    if (strncmp(lastLine2, line2, 20) != 0)
    {
        strncpy(lastLine2, line2, 20);
        lastLine2[20] = '\0';
        lcd->locate(0, 10);
        lcd->printf(line2);
    };
    if (strncmp(lastLine3, line3, 20) != 0)
    {
        strncpy(lastLine3, line3, 20);
        lastLine3[20] = '\0';
        lcd->locate(0, 20);
        lcd->printf(line3);
    };
};

char *LCDManager::batteryMonitorBuffer(BatteryMonitor *Batt)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%2.02f V  ", Batt->getBatteryVoltage());
    return dspBuffer;
};

char *LCDManager::SVB1(TCRT *S3)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%1.02f    ", S3->getSensorVoltage(true));
    return dspBuffer;
};

char *LCDManager::SVB2(TCRT *S1, TCRT *S2, TCRT *S4, TCRT *S5)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%1.02f %1.02f %1.02f %1.02f", S1->getSensorVoltage(true), S2->getSensorVoltage(true), S4->getSensorVoltage(true), S5->getSensorVoltage(true));
    return dspBuffer;
};

char *LCDManager::encoderOutputTest(Encoder *leftWheel, Encoder *rightWheel)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%3.03f    %3.03f ", leftWheel->getDist(), rightWheel->getDist());
    return dspBuffer;
};

char *LCDManager::FloatOutput(float one, float two, float three)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%1.02f  %1.02f  %1.02f", one, two, three);
    return dspBuffer;
};

char *LCDManager::FloatOutput2(float one, float two, float three)
{
    static char dspBuffer[20];
    sprintf(dspBuffer, "%1.02f  %1.02f  %1.02f", one, two, three);
    return dspBuffer;
};
