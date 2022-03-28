#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"

Session::Session(SessionLength* sl, SessionType* st)
{
    leftActive = false;
    rightActive = false;
    intensity = 0;
    length = sl;
    type = st;
}

void Session::increaseIntensity() {
    //Max intensity = 8
    if (intensity < 8) {
        intensity += 1;
    }
}

void Session::decreaseIntensity() {
    //Lowest intensity = 0
    if (intensity > 0) {
        intensity -= 1;
    }
}

void Session::changeSessionType(SessionType * newSt) {
    type = newSt;
}

void Session::changeSessionLength(SessionLength * newSl) {
    length = newSl;
}
