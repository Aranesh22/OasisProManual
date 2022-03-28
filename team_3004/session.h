#ifndef SESSION_H
#define SESSION_H

#include "sessionlength.h"
#include "sessiontype.h"

class Session
{
public:
    Session(SessionLength*, SessionType*);

private:
    SessionLength* length;
    SessionType* type;
    int intensity;
    bool leftActive;
    bool rightActive;

    void increaseIntensity();
    void decreaseIntensity();
    void changeSessionType(SessionType*);
    void changeSessionLength(SessionLength*);
};

#endif // SESSION_H
