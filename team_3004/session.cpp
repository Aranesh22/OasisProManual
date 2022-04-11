#include "session.h"
#include "definitions.h"

#include <stdexcept>


Session::Session(SessionLength* sl, SessionType* st)
{
    curIntensity = MIN_INTENSITY;
    leftActive = false;
    rightActive = false;
    softOffState = false;
    length = sl;
    type = st;
    minsPassed = 0;
    paused = false;
}

//getters
SessionLength* Session::getLength(){return length;}
SessionType* Session::getType(){return type;}
int Session::getCurIntensity(){return curIntensity;}
bool Session::isLeftActive(){return leftActive;}
bool Session::isRightActive(){return rightActive;}
int Session::getMinsPassed(){return minsPassed;}

//setters
void Session::setCurIntensity(int newIntensity) {
    curIntensity = newIntensity;
}

void Session::incInten(){
    if(curIntensity != MAX_INTENSITY) curIntensity++;
}

void Session::decInten(){
    if(curIntensity != MIN_INTENSITY) curIntensity--;
}

int Session::adjustIntensity(bool connectionTest, bool upArrow, bool downArrow, bool skinIrritation) {
    //Returning current intensity or error value (-1) to inform interface which number should be lit
    //Constructor covers first step


    if (!connectionTest || skinIrritation) {
        //Can't do anything since precondition needs connection test to pass
        return -1;
    }
    if ((upArrow == true && downArrow == true) || (upArrow == false && downArrow == false)) {
        //Can't press both buttons at the same time
        return -1;
    }

    if (upArrow) {
        incInten();
        return curIntensity;
    }
    else if (downArrow) {
        decInten();
        return curIntensity;
    }
}

bool Session::endSession(bool pressPower) {
    //If function returns false: end session has failed and softoffstate should be off
    //If function returns true: end session has worked and softoffstate should be on (in this case make sure to handle device turning off)
    //Extensions can't really be applied to this function

    if (!pressPower || softOffState) {
        //Must ensure that power button is pressed
        return false;
    }

    int currentIntensity = 3;

    while(1) {
        if (currentIntensity == 0) {
            break;
        }
        decInten();

        //This is where we would have to update the interface to show intensity decreasing
    }

    softOffState = true;
    return softOffState;
}

int Session::elapseMinute(){
    minsPassed++;
    return minsPassed;
}

void Session::pause(){ paused = true; }

void Session::unpause(){ paused = false; }

bool Session::isPaused(){ return paused; }

