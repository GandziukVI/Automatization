#ifndef IEXPERIMENTALDEVICE_H
#define IEXPERIMENTALDEVICE_H

class IExperimentalDevice
{
public:
    virtual bool InitDevice () = 0;
    virtual bool SendCommandRequest            (const char* RequestString) = 0;

    virtual unsigned char* ReceiveDeviceAnsver () = 0;
    virtual unsigned char* RequestQuery        (const char* Query) = 0;

    virtual ~IExperimentalDevice() { }
};

#endif // IEXPERIMENTALDEVICE_H

