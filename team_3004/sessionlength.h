#ifndef SESSIONLENGTH_H
#define SESSIONLENGTH_H
#include "definitions.h"



class SessionLength
{  

private:

    int durationMins;
    bool isCustom;
    int getDurationMins();


public:
    
    SessionLength(int, bool);
    bool getIsCustom();

};

#endif // SESSIONLENGTH_H
