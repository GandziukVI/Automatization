#ifndef KEITHLEY26XXSMUX_H
#define KEITHLEY26XXSMUX_H

#include <string>

#include "../../DeviceIO/includes/IDeviceIO.h"

#include "Keithley26xxLimit.h"
#include "Keithley26xxMeasure.h"

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

        limit = new Keithley26xxLimit(Driver, channelID);
        measure = new Keithley26xxMeasure(Driver, channelID);
    }

    Keithley26xxLimit getLimit() const
    {
        return limit;
    }

    Keithley26xxMeasure getMeasure() const
    {
        return measure;
    }

    ~Keithley26xxSmuX()
    {
        if(_driver)
            delete _driver;
        if(_channelID)
            delete _channelID;

        if(limit)
            delete limit;
        if(measure)
            delete measure;
    }

private:
    IDeviceIO* _driver;
    const char* _channelID;

    Keithley26xxLimit* limit;
    Keithley26xxMeasure* measure;
};

#endif // KEITHLEY26XXSMUX_H

