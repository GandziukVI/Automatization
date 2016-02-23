#ifndef VISADEVICE_H
#define VISADEVICE_H

#include "iexperimentaldevice.h"

#include <visa.h>
#include <visatype.h>

#include <QString>

#define stringLen 256
#define writeBufferCount 512
#define readBufferCount 1048576
#define connectionTimeout 120000

class VisaDevice : public IExperimentalDevice
{
public:
    VisaDevice(const char* VisaID)
    {
        strcpy_s(ID, VisaID);
    }

    VisaDevice(QString& VisaID)
    {
        const char* _visaID = VisaID.toLatin1().constData();
        strcpy_s(ID, _visaID);
    }

    ~VisaDevice()
    {
        Close();
    }

    bool InitDevice ()
    {
        status = viOpenDefaultRM(&defaultRM);

        if(status < VI_SUCCESS)
            return false;
        else
        {
            status = viOpen (defaultRM, ID, VI_NULL, VI_NULL, &instr);

            if(status < VI_SUCCESS){
                Close();
                return false;
            }

            status = viSetAttribute(instr, VI_ATTR_TMO_VALUE, connectionTimeout);

            return true;
        }
    }

    bool SendCommandRequest (const char* RequestString)
    {
        strcpy_s(stringinput, RequestString);
        status = viWrite(instr, (ViBuf)stringinput, (ViUInt32)strlen(stringinput), &writeCount);

        if(status < VI_SUCCESS) {
            Close();
            return false;
        }
        else
            return true;
    }

    unsigned char* ReceiveDeviceAnsver ()
    {
        status = viRead (instr, buffer, readBufferCount, &retCount);

        if(status < VI_SUCCESS)
            Close();

        return buffer;
    }

    unsigned char* RequestQuery (const char *Query)
    {
        SendCommandRequest(Query);
        return ReceiveDeviceAnsver();
    }

private:
    char ID[stringLen];

    ViSession defaultRM;
    ViSession instr;
    ViStatus status;
    ViUInt32 retCount;
    ViUInt32 writeCount;

    unsigned char buffer[readBufferCount];
    char stringinput[writeBufferCount];

    void Close()
    {
        status = viClose(instr);
        status = viClose(defaultRM);
    }
};

#endif // VISADEVICE_H

