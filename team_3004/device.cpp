#include "device.h"

//used to test connection
//#include <wininet.h>
//#pragma comment(lib,"Wininet.lib")

Device::Device()
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
    battery = new Battery();
    connection = none;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();
    curSession = nullptr;
    //allLengths = ???
    //allTypes = ???

}

//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}

void Device::turnOn(){
    power = on;
}

void Device::turnOff(){
    power = off;
}

ConnectionState Device::testForConnection(){

}
