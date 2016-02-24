#ifndef KEITHLEY26XX_DISPLAY_H
#define KEITHLEY26XX_DISPLAY_H

#include <string>

#include "../DeviceIO/includes/IDeviceIO.h"
#include "../Keithley26xxDefinitions.h"

class Keithley26xx_Display
{
public:
    Keithley26xx_Display(IDeviceIO& Driver, const char* channelID)
    {
        _driver = new IDeviceIO;
        memcpy_s(_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        int len = strlen(channelID);
        strncpy(_channelID, channelID, len);
    }

    ~Keithley26xx_Display()
    {
        delete _driver;
        delete _channelID;
    }

private:
    IDeviceIO* _driver;
    const char* _channelID;
};

#endif // KEITHLEY26XX_DISPLAY_H

