#ifndef SESSIONTYPE_H
#define SESSIONTYPE_H
#include "definitions.h"



class SessionType
{
public:
    SessionType(float, float, CEStype);
    float getMaxHz();
    float getMinHz();
    CEStype getCESType();




private:
    float minHz;
    float maxHz;
    CEStype csMode;

};

#endif // SESSIONTYPE_H
