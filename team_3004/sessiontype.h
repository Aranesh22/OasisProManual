#ifndef SESSIONTYPE_H
#define SESSIONTYPE_H
#include "definitions.h"



class SessionType
{
public:
    SessionType(float, CEStype);

private:
    float hz;
    CEStype csMode;

};

#endif // SESSIONTYPE_H
