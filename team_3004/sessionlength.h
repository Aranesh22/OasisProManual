/*
 * Represents the sesion length of a session
 * Avaialbe session lengths are 25 mins, 45 mins, 3 hours, and a custom length
 *
 * Notable data members:
 *  icon - Stores the icon that links the session length to the UI elements
 */

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
    int getDurationMins();


private:
    int durationMins;
    bool isCustom;
    DisplayIcon* icon;

    bool getIsCustom();
};

#endif // SESSIONLENGTH_H
