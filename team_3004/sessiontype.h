#ifndef SESSIONTYPE_H
#define SESSIONTYPE_H
#include "definitions.h"
#include "displayicon.h"
class SessionType
{
public:
    SessionType(float, float, CEStype);
    SessionType(float, float, CEStype, DisplayIcon*);
    SessionType(float, float, CEStype, DisplayIcon*, DisplayIcon*);
    friend class Session;

    DisplayIcon* getIcon();
    DisplayIcon* getCESIcon();

private:
    float minHz;
    float maxHz;
    CEStype csMode;
    float getMaxHz();
    float getMinHz();
    CEStype getCESType();
    DisplayIcon* icon;
    DisplayIcon* CESicon;
};

#endif // SESSIONTYPE_H
