#ifndef SESSIONLENGTH_H
#define SESSIONLENGTH_H
#include "definitions.h"

class SessionLength
{  
public:
    SessionLength(int, bool);
    friend class Session;

private:
    int durationMins;
    bool isCustom;

    int getDurationMins();
    bool getIsCustom();
};

#endif // SESSIONLENGTH_H
