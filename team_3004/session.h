#ifndef SESSION_H
#define SESSION_H

#include "sessionlength.h"
#include "sessiontype.h"

class Session
{
public:
    friend class SessionType;
    friend class SessionLength;

    Session(SessionLength*, SessionType*);

    //getters
    SessionLength* getLength();
    SessionType* getType();
    int getCurIntensity();
    bool isLeftActive();
    bool isRightActive();

    void incInten();
    void decInten();

private:
    SessionLength* length;
    SessionType* type;
    int curIntensity;
    bool leftActive;
    bool rightActive;
};

#endif // SESSION_H
