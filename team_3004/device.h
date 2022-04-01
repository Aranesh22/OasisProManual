#ifndef DEVICE_H
#define DEVICE_H

#include <vector>

#include "definitions.h"
#include "button.h"
#include "historymanager.h"
#include "battery.h"
#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"

using namespace std;

class Device
{
public:
    Device();

    //getters
    PowerState getPower();
    Battery* getBattery();
    bool isOutputtingAudio();
    HistoryManager* getHistory();
    Session* getCurSession();
    vector<SessionLength*> getAllLengths;
    vector<SessionType*> getAllTypes;



    //setters or equivalent
    void turnOn();
    void turnOff();
    void setSession(Session*);
    ConnectionState testForConnection(); //always sets connection to true bc we have no way to test for connectivity

    void handleLowBattery();
    void editSesLen();
    void nextSesLen();
    void prevSesLen();

private:
    vector<Button*> buttons;
    Battery* battery;
    ConnectionState connection;
    PowerState power;
    bool outputtingAudio;

    HistoryManager* history;
    Session* curSession;
    vector<SessionLength*> allLengths;
    vector<SessionType*> allTypes;

    UseCase curUseCase;

    SessionLength* curSesLength; //list of the currently highlighted / running session length
    SessionType* curSesType; //list of currently highlighted / running session type

    void initAllLength();
    void initAllTypes();
    int indexOf(SessionLength*);
    int indexOf(SessionType*);


};

#endif // DEVICE_H
