#ifndef KEITHLEY26XX_DISPLAY_H
#define KEITHLEY26XX_DISPLAY_H

#include <string>

#include "../DeviceIO/includes/IDeviceIO.h"
#include "../Keithley26xxDefinitions.h"

#include "Keithley26xxSmuX.h"

class Keithley26xx_Display
{
public:
    Keithley26xx_Display(IDeviceIO& Driver, const char* channelID)
    {
        _driver = new IDeviceIO;
        memcpy_s(_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        int len = strlen(channelID);
        strncpy(_channelID, channelID, len);

        smuX = new Keithley26xxSmuX(Driver, channelID);
    }

    ~Keithley26xx_Display()
    {
        if(_driver)
            delete _driver;
        if(_channelID)
            delete _channelID;

        if(smuX)
            delete smuX;
    }

    void Clear() const
    {
        _driver->SendCommandRequest("display.clear()");
    }

private:
    IDeviceIO* _driver;
    const char* _channelID;

    Keithley26xxSmuX* smuX;

    const char command[256];
    const char message[256];
};

#endif // KEITHLEY26XX_DISPLAY_H

