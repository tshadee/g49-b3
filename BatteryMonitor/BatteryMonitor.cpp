#include "BatteryMonitor.h"
#include "CommonDefs.h"
#include "ds2781.h"
#include "OneWire_Methods.h"

// use the one-wire-pin PC_12
BatteryMonitor::BatteryMonitor(DigitalInOut *OWP) : one_wire_pin(OWP)
{
    VoltageReading = ReadVoltage();
    Voltage = VoltageReading * 0.00967;
};
void BatteryMonitor::pollBattery(void)
{
    VoltageReading = ReadVoltage();
    Voltage = ((float)VoltageReading) * 0.00967;
};

float BatteryMonitor::getBatteryVoltage(void) { return Voltage; };
