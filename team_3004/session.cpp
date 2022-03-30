#include "session.h"
#include "definitions.h"

#include <stdexcept>


Session::Session(SessionLength* sl, SessionType* st)
{
    curIntensity = MIN_INTENSITY;
    leftActive = false;
    rightActive = false;
    length = sl;
    type = st;
    minsPassed = 0;
}

//getters
SessionLength* Session::getLength(){return length;}
SessionType* Session::getType(){return type;}
int Session::getCurIntensity(){return curIntensity;}
bool Session::isLeftActive(){return leftActive;}
bool Session::isRightActive(){return rightActive;}
int Session::getMinsPAssed(){return minsPassed;}

void Session::incInten(){
    curIntensity == MAX_INTENSITY ? curIntensity = MIN_INTENSITY : curIntensity++;
}

void Session::decInten(){
    curIntensity == MIN_INTENSITY ? curIntensity = MAX_INTENSITY : curIntensity--;
}
