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
    VisaDevice/includes/visadevice.h \
    VisaDevice/includes/iexperimentaldevice.h \
    VisaDevice/includes/tests.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/VisaDevice/includes/Visa/lib/ -lvisa32

#win32: LIBS += "C:/Users/v.handziuk/Documents/GitHub/Automatization/VisaDevice/includes/Visa/lib/visa64.lib"

INCLUDEPATH += $$PWD/VisaDevice/includes/Visa/include
DEPENDPATH += $$PWD/VisaDevice/includes/Visa/include
