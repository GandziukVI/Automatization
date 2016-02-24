#ifndef KEITHLEY26XXSMUX_H
#define KEITHLEY26XXSMUX_H

#include <string>

#include "../../DeviceIO/includes/IDeviceIO.h"

class Keithley26xxSmuX
{
public:
    Keithley26xxSmuX(IDeviceIO& Driver, const char* channelID)
    {
        _driver = new IDeviceIO;
        memcpy_s (_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        int len = strlen(channelID);
        _channelID = new const char* [len];
        strncpy(_channelID, channelID, len);
    }

    ~Keithley26xxSmuX()
    {
        if(_driver)
            delete _driver;
        if(_channelID)
            delete _channelID;
    }

private:
    IDeviceIO* _driver;
    const char* _channelID;
};

#endif // KEITHLEY26XXSMUX_H

