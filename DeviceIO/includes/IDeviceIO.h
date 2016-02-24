#ifndef IEXPERIMENTALDEVICE_H
#define IEXPERIMENTALDEVICE_H

class IDeviceIO
{
public:
    IDeviceIO () { }

    virtual bool InitDevice () = 0;
    virtual bool SendCommandRequest            (const char* RequestString) = 0;

    virtual unsigned char* ReceiveDeviceAnsver () = 0;
    virtual unsigned char* RequestQuery        (const char* Query) = 0;

    virtual ~IDeviceIO() { }
};

#endif // IEXPERIMENTALDEVICE_H

