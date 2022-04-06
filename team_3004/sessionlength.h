#ifndef SESSIONLENGTH_H
#define SESSIONLENGTH_H
#include "definitions.h"
#include "displayicon.h"

class SessionLength
{  
public:
    SessionLength(int, bool);
    SessionLength(int, bool, DisplayIcon*);
    friend class Session;

    DisplayIcon* getIcon();


private:
    int durationMins;
    bool isCustom;
    DisplayIcon* icon;

    int getDurationMins();
    bool getIsCustom();
};

#endif // SESSIONLENGTH_H
