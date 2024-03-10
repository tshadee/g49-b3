#include "ExternalStimulus.h"

// UserInputInterrupts::UserInputInterrupts(PinName centre, PinName TX, PinName RX, PinName USBTX, PinName USBRX) : centreJoy(centre), toggleState(false), HM10(TX,RX), PC(USBTX,USBRX)
ExternalStim::ExternalStim(PinName TX, PinName RX) : HM10(TX, RX)
{
    intRC = 0;
    KP = KD = KI = 0.0f;
};

bool ExternalStim::serialConfigReady()
{
    HM10.baud(9600);
    while (!HM10.writeable()){};
    // blePollTicker.attach(callback(this,&ExternalStim::pullHM10), (1.0 / BLE_POLL_RATE));
    return true;
};

bool ExternalStim::pullHM10()
{
    if (HM10.readable())
    {
        intRC = HM10.getc();
        // KP = HM10.getc();
        // KD = HM10.getc();
        // KI = HM10.getc();
        return true;
    }
    else
    {
        return false;
    };
};

// bool ExternalStim::pullHM10()
// {
//     if (HM10.readable())
//     {
//         bleToData = HM10.getc();            //read one byte
//         dataBuffer[index++] = bleToData;    //store byte in data buffer

//         if(index == BLE_BYTE_LENGTH)
//         {
//             memcpy(&intRC, dataBuffer, 4);
//             memcpy(&KP, dataBuffer + 4, 4);
//             memcpy(&KD, dataBuffer + 8, 4);
//             memcpy(&KI, dataBuffer + 12, 4);
//             index = 0;
//         };
//         return true;
//     }
//     else
//     {
//         return false;
//     };
// };

float ExternalStim::getKP()
{
    return KP;
};

float ExternalStim::getKD()
{
    return KD;
};

float ExternalStim::getKI()
{
    return KI;
};

int ExternalStim::getIntRC()
{
    return intRC;
};
