#include "device.h"

Device::Device(Battery* b)
{
    /*
    vector<Button*> buttons;
    Battery* battery;
    ConnectionState connection;
    bool power;
    bool curOutputtingAudio;

    HistoryManager* history;
    Session* curSession;
    vector<SessionLength*> allLengths;
    vector<SessionType*> allTypes;
     */

    //buttons = ???
    battery = b;
    connection = none;
    power = off;
    curOutputtingAudio = false;

    history = new HistoryManager();
    curSession = nullptr;
    //allLengths = ???
    //allTypes = ???

}

void Device::turnOn(){
    power = on;
}

void Device::turnOff(){
    power = off;
}

