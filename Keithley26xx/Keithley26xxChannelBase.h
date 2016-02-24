#ifndef KEITHLEY26XXCHANNELBASE_H
#define KEITHLEY26XXCHANNELBASE_H

#include "../DeviceIO/includes/IDeviceIO.h"
#include "../DeviceIO/includes/VisaDevice.h"

#include "../DeviceIO/includes/ISourceMeterUnit.h"

#include "Keithley26xx_Display.h"

class Keithley26xxChannelBase : public ISourceMeterUnit
{
public:
    Keithley26xxChannelBase() { }
    ~Keithley26xxChannelBase()
    {
        if(_driver)
            delete _driver;
        if(_display)
            delete _display;
    }

    int getNumberOfChannels() const
    {
        return NumberOfChannels;
    }

    void setNumberOfChannels(int val)
    {
        NumberOfChannels = val;
    }

    const char* getChannelIdentifier() const
    {
        return ChannelIdentifier;
    }

    void Initialize(IDeviceIO& Driver)
    {
        Initialize(Driver, "a");
    }

    void Initialize(IDeviceIO& Driver, const char* channelID)
    {
        if(_driver)
            delete _driver;

        _driver = new IDeviceIO;
        memcpy_s(_driver, sizeof(IDeviceIO*), &Driver, sizeof(IDeviceIO));
        setChannelIdentifier(channelID);
    }

protected:
    void setChannelIdentifier(const char* ChannelID)
    {
        if(ChannelIdentifier)
            delete ChannelIdentifier;
        else
        {
            size_t len = strlen(ChannelID);
            ChannelIdentifier = new const char* [len];
            strncpy(ChannelIdentifier, ChannelID, len);
        }
    }

private:
    int NumberOfChannels;
    const char* ChannelIdentifier;

    IDeviceIO* _driver;
    Keithley26xx_Display* _display;
};

#endif // KEITHLEY26XXCHANNELBASE_H

