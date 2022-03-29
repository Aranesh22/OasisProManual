#include "session.h"
#include "definitions.h"

#include <stdexcept>


Session::Session(SessionLength* sl, SessionType* st, int i)
{
    if(i < 1 || i > MAX_INTENSITY) throw std::invalid_argument( "received invalid interval value" );

    curIntensity = i;
    leftActive = false;
    rightActive = false;
    length = sl;
    type = st;
}

//getters
SessionLength* Session::getLength(){return length;}
SessionType* Session::getType(){return type;}
int Session::getCurIntensity(){return curIntensity;}
bool Session::isLeftActive(){return leftActive;}
bool Session::isRightActive(){return rightActive;}
