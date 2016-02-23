#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T16:06:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Automatization
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \

HEADERS  += mainwindow.h \
    DeviceIO/includes/VisaDevice.h \
    DeviceIO/includes/IDeviceIO.h \
    DeviceIO/includes/tests.h \
    DeviceIO/includes/ISourceMeterUnit.h \
    DeviceIO/includes/Definitions.h \
    Math/FFT.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/DeviceIO/includes/Visa/lib/ -lvisa32

INCLUDEPATH += $$PWD/DeviceIO/includes/Visa/include
DEPENDPATH += $$PWD/DeviceIO/includes/Visa/include
