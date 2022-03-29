#ifndef SESSION_H
#define SESSION_H

#include "sessionlength.h"
#include "sessiontype.h"

class Session
{
public:
    Session(SessionLength*, SessionType*, int);

private:
    SessionLength* length;
    SessionType* type;
    int curIntensity;
    bool leftActive;
    bool rightActive;
};

#endif // SESSION_H
