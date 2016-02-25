#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>
#include <exception>

enum SourceMode
{
    Voltage,
    Current,
    ModeNotSet
};

enum SenseMode
{
    Voltage,
    Current,
    Resistance,
    ModeNotSet
};

enum OhmsMode
{
    Auto,
    Manual,
    ModeNotSet
};

enum AutoZeroMode
{
    ON,
    OFF
};

class ProgramException : public exception
{
public:
    ProgramException(const char* message)
    {
        strcpy_s(_message, message);
    }

    virtual const char* what() const throw()
    {
        return _message;
    }
private:
    const char _message[256];
};

#endif // DEFINITIONS_H

