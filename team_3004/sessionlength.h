#ifndef SESSIONLENGTH_H
#define SESSIONLENGTH_H
#include "definitions.h"



class SessionLength
{  

private:

    int durationMins;
    bool isCustom;
    int getDurationMins();
    bool getIsCustom();

public:
    
    SessionLength(int, bool);

};

#endif // SESSIONLENGTH_H
