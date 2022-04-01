#include "device.h"

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
//    allLengths = initAllLengths();
//    allTypes = initAllTypes();
    curSesLength = nullptr;
    curSesType = nullptr;

}

//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}

UseCase Device::getCurUseCase() {return curUseCase;}

//vector<SessionLength*> Device::getAllLengths{return allLengths;}
//vector<SessionType*> Device::getAllTypes{return allTypes;}

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

void Device::nextSesLen(){
    int i = indexOf(curSesLength)+1;
    if( i == allLengths.size() ) i = 0;
    curSesLength = allLengths[i];
}

void Device::prevSesLen(){
    int i = indexOf(curSesLength)-1;
    if( i < 0 ) i = allLengths.size() - 1;
    curSesLength = allLengths[i];
}

int Device::indexOf(SessionLength* sl){
    for(int i=0; i<allLengths.size(); i++){
        if(allLengths[i] == sl) return i;
    }
    return -1;
}

int Device::indexOf(SessionType* st){
    for(int i=0; i<allTypes.size(); i++){
        if(allTypes[i] == st) return i;
    }
    return -1;
}
