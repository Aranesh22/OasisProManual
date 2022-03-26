#ifndef SESSION_H
#define SESSION_H

#include "sessionlength.h"
#include "sessiontype.h"

class Session
{
public:
    Session(SessionLength*, SessionType*, bool, bool);
    ~Session();

private:
    SessionLength* length;
    SessionType* type;
    int intensity;
    bool leftActive;
    bool rightActive;
};

#endif // SESSION_H
