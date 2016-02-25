#ifndef KEITHLEY26XXMEASURE_H
#define KEITHLEY26XXMEASURE_H

#include <string>

#include "../../DeviceIO/includes/Definitions.h"
#include "../../DeviceIO/includes/IDeviceIO.h"

#include "../Keithley26xxDefinitions.h"

class Keithley26xxMeasure
{
public:
    Keithley26xxMeasure(IDeviceIO& Driver, const char* channelID)
    {
        _driver = new IDeviceIO;
        memcpy_s(_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        int len = strlen(channelID);
        strncpy(_channelID, channelID, len);
    }

    ~Keithley26xxMeasure()
    {
        if(_driver)
            delete _driver;
        if(_channelID)
            delete _channelID;
    }

    void setFunc(Keithley26xxMeasureFunctions func) const
    {
        ssprintf_s(command, "display.smu%s.measure.func = %d", _channelID, (int)func);
        _driver->SendCommandRequest(command);
    }

    Keithley26xxMeasureFunctions getFunc()
    {
        sprintf_s(command, "smu%sMeasureFunc = display.smu%s.measure.func", _channelID, _channelID);
        _driver->SendCommandRequest(command);
        sprintf_s(command, "print(smu%sMeasureFunc)", _channelID);
        const char* responce = _driver->RequestQuery(command);

        double doubleResponce = 0.0;
        if(sscanf(responce, "%f", &doubleResponce) > 0)
        {
            if (0 == (int)doubleResponce)
                return MEASURE_DCAMPS;
            else if (1 == (int)doubleResponce)
                return MEASURE_DCVOLTS;
            else if (2 == (int)doubleResponce)
                return MEASURE_OHMS;
            else if (3 == (int)doubleResponce)
                return MEASURE_WATTS;
            else
            {
                sprintf_s(message, "Can't read smu%s measure function!", _channelID);
                throw ProgramException(message);
            }
        }
        else
        {
            if (responce == "0" || responce == "display.MEASURE_DCAMPS")
                return MEASURE_DCAMPS;
            else if (responce == "1" || responce == "display.MEASURE_DCVOLTS")
                return MEASURE_DCVOLTS;
            else if (responce == "2" || responce == "MEASURE_OHMS")
                return MEASURE_OHMS;
            else if (responce == "3" || responce == "display.MEASURE_WATTS")
                return MEASURE_WATTS;
            else
            {
                sprintf_s(message, "Can't read smu%s measure function!", _channelID);
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

#endif // KEITHLEY26XXMEASURE_H
