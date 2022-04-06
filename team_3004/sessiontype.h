#ifndef SESSIONTYPE_H
#define SESSIONTYPE_H
#include "definitions.h"
#include "displayicon.h"
class SessionType
{
public:
    SessionType(float, float, CEStype);
    SessionType(float, float, CEStype, DisplayIcon*);
    friend class Session;

    DisplayIcon* getIcon();

private:
    float minHz;
    float maxHz;
    CEStype csMode;
    float getMaxHz();
    float getMinHz();
    CEStype getCESType();
    DisplayIcon* icon;

};

#endif // SESSIONTYPE_H
