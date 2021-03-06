/*
 * Represents a session
 * Which contains a SessionLength and SessionType instances
 * See SessionLength and SessionType for more info
 */

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
    void setCurIntensity(int);

    void incInten();
    void decInten();

    int adjustIntensity(bool,bool,bool,bool);
    bool endSession(bool);

    int elapseMinute();

    void pause();
    void unpause();
    bool isPaused();

private:
    SessionLength* length;
    SessionType* type;
    int curIntensity;
    bool leftActive;
    bool rightActive;
    int minsPassed;
    bool softOffState; //unused

    bool paused;
};

#endif // SESSION_H
