#ifndef ISOURCEMETERUNIT_H
#define ISOURCEMETERUNIT_H

#include "IDeviceIO.h"

class ISourceMeterUnit
{
public:
    virtual void Initialize (IDeviceIO Driver) = 0;
    virtual void Initialize (IDeviceIO Driver, const char* channelID) = 0;

    virtual void SwitchON () = 0;
    virtual void SwitchOFF () = 0;

    virtual void setSourceVoltage (double val) = 0;
    virtual void setSourceCurrent (double val) = 0;
    virtual void setCompliance (double val) = 0;

    virtual void setSourceDelay (double val) = 0;

    virtual void setPulseWidth (double val) = 0;
    virtual void setPulseDelay (double val) = 0;

    virtual void setAveraging (int avg) = 0;
    virtual void setNPLC (double val) = 0;

    virtual double getVoltage () = 0;
    virtual double getCurrent () = 0;
    virtual double getResistance () = 0;
    virtual double getCompliance () = 0;

    virtual double getAveraging () = 0;
    virtual double getNPLC () = 0;

    virtual double getPulseWidth() = 0;
    virtual double getPulseDelay() = 0;

};

#endif // ISOURCEMETERUNIT_H

