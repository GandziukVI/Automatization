#ifndef KEITHLEY26XXDEFINITIONS_H
#define KEITHLEY26XXDEFINITIONS_H

enum Keithley26xxAvailableChannels
{
    SMUA = 0,
    SMUB = 1,
    SMUA_SMU_B = 2,
    USER = 3
};

enum Keithley26xxLimitFunctions
{
    LIMIT_IV = 0,
    LIMIT_P = 1
};

enum Keithley26xxMeasureFunctions
{
    MEASURE_DCAMPS = 0,
    MEASURE_DCVOLTS = 1,
    MEASURE_OHMS = 2,
    MEASURE_WATTS = 3,
};

#endif // KEITHLEY26XXDEFINITIONS_H

