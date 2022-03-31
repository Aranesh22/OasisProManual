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
    connection = disconnected;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();
    curSession = nullptr;
    curUseCase = blank;
    //allLengths = ???
    //allTypes = ???
    curSesLength = nullptr;
    curSesType = nullptr;

}

//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}

void Device::turnOn(){
    curUseCase = displayingBattery;
    power = on;
}

void Device::turnOff(){
    power = off;
    curUseCase = blank;
}

ConnectionState Device::testForConnection(){
    curUseCase = loadingConnection;
    connection = connected;
    return connection;
}

void Device::handleLowBattery(){
//    if(curUseCase == runningSession) curSession->end();
    curUseCase = lowBattery;

}

void Device::setSession(Session* s){
    curSession = s;
}
