#ifndef SESSIONTYPE_H
#define SESSIONTYPE_H
#include "definitions.h"

class SessionType
{
public:
    SessionType(float, float, CEStype);
    friend class Session;

private:
    float minHz;
    float maxHz;
    CEStype csMode;
    float getMaxHz();
    float getMinHz();
    CEStype getCESType();

};

#endif // SESSIONTYPE_H
