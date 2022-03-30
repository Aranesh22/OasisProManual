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

    PowerState getPower();
    Battery* getBattery();
    bool isOutputtingAudio();
    HistoryManager* getHistory();
    Session* getCurSession();

    void turnOn();
    void turnOff();

    ConnectionState testForConnection();

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

};

#endif // DEVICE_H
