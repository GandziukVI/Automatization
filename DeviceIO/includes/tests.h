#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QString>

#include "IDeviceIO.h"
#include "VisaDevice.h"

class SuperClass : public QObject
{
    Q_OBJECT
signals:
    void PrintRequest(QString request);
public slots:
    void RequestSubmitted (bool)
    {
        IDeviceIO *theDevice = new VisaDevice("USB0::0x0957::0x1718::TW54334510::INSTR");
        theDevice->InitDevice();

        QString res = QString((const char*)theDevice->RequestQuery("*IDN?"));

        emit PrintRequest(res);
        delete theDevice;
    }
};

#endif // TESTS_H

