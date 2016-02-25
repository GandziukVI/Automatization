#ifndef KEITHLEY26XXLIMIT_H
#define KEITHLEY26XXLIMIT_H

#include <string>

#include "../../DeviceIO/includes/Definitions.h"
#include "../../DeviceIO/includes/IDeviceIO.h"

#include "../Keithley26xxDefinitions.h"

class Keithley26xxLimit
{
public:
    Keithley26xxLimit (IDeviceIO& Driver, const char* channelID)
    {
        _driver = new IDeviceIO;
        memcpy_s(_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        int len = strlen(channelID);
        srtncpy(_channelID, channelID, len);
    }

    ~Keithley26xxLimit()
    {
        if(_driver)
            delete _driver;
        if(_channelID)
            delete _channelID;
    }

    void setFunc (Keithley26xxLimitFunctions func)
    {
        sprintf_s(command, "display.smu%s.lamat.func = %d", _channelID, (int)func);
        _driver->SendCommandRequest(command);
    }

    Keithley26xxLimitFunctions getFunc()
    {
        command[256];
        sprintf_s(command, "display%sLimitFunc = display.smu%s.limit.func", _channelID, _channelID);
        _driver->SendCommandRequest(command);
        sprintf_s(command, "print(display%sLimitFunc", _channelID);
        const char* responce = _driver->RequestQuery(command);
        double doubleResponce = 0.0;
        if(sscanf(responce, "%f", &doubleResponce) > 0)
        {
            if(0 == (int)doubleResponce)
                return LIMIT_IV;
            else if (1 == (int)doubleResponce)
                return LIMIT_P;
            else
            {
                sprintf_s(message, "Can't read smu%s limit function!", _channelID);
                throw ProgramException(message);
            }
        }
        else
        {
            if(responce == "0" || responce == "display.LIMIT_IV")
                return LIMIT_IV;
            else if (responce == "1" || responce == "display.LIMIT_P")
                return LIMIT_P;
            else
            {
                sprintf_s(message, "Can't read smu%s limit function!", _channelID);
                throw ProgramException(message);
            }
        }
    }

private:
    IDeviceIO* _driver;
    const char* _channelID;

    const char command[256];
    const char message[256];
};

#endif // KEITHLEY26XXLIMIT_H

