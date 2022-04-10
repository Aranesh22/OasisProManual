#ifndef SESSION_H
#define SESSION_H

#include "sessionlength.h"
#include "sessiontype.h"


class Session
{
public:
    Session(SessionLength*, SessionType*);

    //getters
    SessionLength* getLength();
    SessionType* getType();
    int getCurIntensity();
    bool isLeftActive();
    bool isRightActive();
    int getMinsPassed();

    void incInten();
    void decInten();

    int adjustIntensity(bool,bool,bool,bool);
    bool endSession(bool);

    int elapseMinute();

    void pause();
    void unpause();

private:
    SessionLength* length;
    SessionType* type;
    int curIntensity;
    bool leftActive;
    bool rightActive;
    int minsPassed;
    bool softOffState;

    bool paused;
};

#endif // SESSION_H
