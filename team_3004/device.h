#ifndef DEVICE_H
#define DEVICE_H

#include <vector>

#include "definitions.h"
#include "historymanager.h"
#include "battery.h"
#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displayicon.h"
#include "historymanager.h"




class Device : public QObject
{
   Q_OBJECT

public:
    Device(Ui::MainWindow*);
    Device();

    //getters
    PowerState getPower();
    Battery* getBattery();
    bool isOutputtingAudio();
    HistoryManager* getHistory();
    Session* getCurSession();
    vector<SessionLength*> getAllLengths();
    vector<SessionType*> getAllTypes();
    UseCase getCurUseCase();
    vector<DisplayIcon*> getIcons();

    //setters or equivalent
    void turnOn();
    void turnOff();
    void setSession(Session*);

    //system events
    void handleLowBattery();
    ConnectionState testForConnection(); //always sets connection to true bc we have no way to test for connectivity
    void batteryLevels();

    //user inputs
    void handleUpArrow();
    void handleDownArrow();
    void handlePowerButton();
    void handleSave();
    void handleCheck();
    vector<QString> uploadSaveSession();

private:
    Ui::MainWindow* ui;

    vector<DisplayIcon*> icons;
    Battery* battery;
    ConnectionState connection;
    PowerState power;
    bool outputtingAudio;
    HistoryManager* history;
    vector<SessionLength*> allLengths;
    vector<SessionType*> allTypes;

    UseCase curUseCase; //the current "use case" of the device; see definitions.h for more detail
    Session* curSession; //if a session is running, this pointer points to its current instance
    SessionLength* curSesLength; //list of the currently highlighted / running session length
    SessionType* curSesType; //list of currently highlighted / running session type


    //initializers
    void initSessionTypes();
    void initAllLength();
    void initAllTypes();
    void initIcons();
    void initClickableIcons();
    void initSessionLengthIcons();
    void initSessionTypeIcons();
    void initOtherIcons();
    void initSesssionLengths();




    //user inputs
    void nextSesLen();
    void nextSesType();
    void prevSesType();
    void startSession();
    void incIntensity();
    void decIntensity();

    //helpers
    int indexOf(SessionLength*);
    int indexOf(SessionType*);

};

#endif // DEVICE_H
