#include "device.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QTime>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

using namespace std;


Device::Device(Ui::MainWindow* ui) : ui(ui)
{

    battery = new Battery();
    connection = none;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();
//    initAllLength();

//    initAllTypes();

    initSesssionLengths();
    initSessionTypes();

    initIcons();

    curSesLength = allLengths[0];
    curSesType = allTypes[0];
    curSession = nullptr;
    curUseCase = blank;


}

Device::Device(){
    qInfo() << "need to update this";
}





//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}
UseCase Device::getCurUseCase() {return curUseCase;}
vector<DisplayIcon*> Device::getIcons(){return icons;}




//system events
void Device::handleLowBattery(){
    curUseCase = lowBattery;
    if(curUseCase == runningSession) endSession();
    curUseCase = blank;
}

void Device::drainBattery(){
    //see definitions.h for more info on MAX_DRAIN and MIN_DRAIN

    /*
     * The step variable determines how every session maps from MAX_DRAIN to MIN_DRAIN
     * To evenly split every intensity from MAX_DRAIN (4) to MIN_DRAIN 3.33
     * We need to subtract 3.33 from 4
     * And divide the output of the above by 8
     */

    float step = (MAX_DRAIN - MIN_DRAIN) / MAX_INTENSITY;
    float drained = MIN_DRAIN + step * curSession->getCurIntensity();
    float remaining = battery->drain(drained);

    if(remaining <= 15) handleLowBattery();
}


ConnectionState Device::testForConnection(){
    curUseCase = loadingConnection;
    connection = CONNECTION_SIM;
    displayConnection();
    return connection;
}

void Device::displayConnection(){
    if(connection == none){
        icons[7]->setIllumState(lit);
        icons[8]->setIllumState(lit);
    }

    if(connection == okay){
        icons[4] -> setIllumState(lit);
        icons[5] -> setIllumState(lit);
        icons[6] -> setIllumState(lit);
    }

    if(connection == excellent){
        icons[1] -> setIllumState(lit);
        icons[2] -> setIllumState(lit);
        icons[3] -> setIllumState(lit);
    }

    delayBy(2);
    resetGraph();
}




//user inputs
void Device::handleUpArrow(){
    //check current use case
    //call the right function
    //is there a better approach that avoids if-else spam / switch?
    //yes; declare maps to function pointers (might be too complicated, so for the scope of this project, if-else spam might be fine)
    qInfo("handle up arrow");
    if(curUseCase == selectingSession) nextSesType();
    else if(curUseCase == runningSession) incIntensity();
}

void Device::handleDownArrow(){
    qInfo("handle down arrow");
    if(curUseCase == selectingSession) prevSesType();
    else if(curUseCase == runningSession) decIntensity();
}

void Device::handlePowerButton(){
    qInfo("handel power button");
    if(curUseCase == blank) turnOn();
    else if(curUseCase == selectingSession) nextSesLen();
    else if (curUseCase == runningSession) endSession();
}


void Device::displayBatteryLevel(){
    for(int i = 1; i <= battery->getBatteryLevel(); i++){
        if(battery->getBatteryLevel() > 2) icons[i]->setIllumState(lit);
//        if(battery->getBatteryLevel() == 2) icons[i]->setIllumState(flashing);
//        if(battery->getBatteryLevel() == 1) icons[i]->setIllumState(flashing);
    }

    delayBy(2);
    resetGraph();


}

void Device::handleSave(){

}

void Device::handleCheck(){
    if(curUseCase == selectingSession) startSession();
}

void Device::nextSesLen(){
    int i = indexOf(curSesLength)+1;
    allLengths[i-1]->getIcon()->toggleIllum();

    if( i == allLengths.size() ) i = 0;
    curSesLength = allLengths[i];

    curSesLength->getIcon()->toggleIllum();
}


void Device::prevSesType(){
    qInfo("prev ses type");
    int i = indexOf(curSesType)-1;
    allTypes[i+1]->getIcon()->toggleIllum();

    if( i < 0 ) i = allTypes.size() - 1;
    curSesType = allTypes[i];

    allTypes[i]->getIcon()->toggleIllum();

}

void Device::nextSesType() {
    qInfo("nextSesType");
    int i = indexOf(curSesType)+1;
    allTypes[i-1]->getIcon()->toggleIllum();

    if( i == allTypes.size() ) i = 0;

    curSesType = allTypes[i];
    allTypes[i]->getIcon()->toggleIllum();
}

void Device::uploadSaveSession() {

    qInfo("Saved Session");
    history->SaveSession(curSession);
    history->getSessions();


}

void Device::startSession(){
    testForConnection();
    curSession = new Session(curSesLength, curSesType);
    curUseCase = runningSession;
    icons[1]->toggleIllum();
}

void Device::endSession(){
    //soft off
    for(int i=curSession->getCurIntensity(); i>=1; i--){
        icons[i]->setIllumState(dim);
        delayBy(1);
    }

    curSession = nullptr;
    turnOff();
}

void Device::softOn(){
//    resetGraph();

    for(int i=1; i<=curSession->getCurIntensity(); i++){
        icons[i]->setIllumState(lit);
        delayBy(1);
    }
}

void Device::incIntensity(){
    curSession->incInten();
    icons[curSession->getCurIntensity() ] -> setIllumState(lit);
}

void Device::decIntensity(){
    if(curSession->getCurIntensity() != MIN_INTENSITY)icons[curSession->getCurIntensity() ] -> setIllumState(dim);
    curSession->decInten();
}


//setters
void Device::turnOn(){
    qInfo("turn on");
    power = on;
    icons[0]->toggleIllum();
    curUseCase = displayingBattery;
    displayBatteryLevel();
    curUseCase = selectingSession;
    curSesLength->getIcon()->toggleIllum();
    curSesType->getIcon()->toggleIllum();

}

void Device::turnOff(){
    power = off;

    for(DisplayIcon* di : icons){
        di->setIllumState(dim);
    }

    curUseCase = blank;
    battery->powerOff();
}

void Device::setSession(Session* s){
    curSession = s;
}







//helpers
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

void Device::delayBy(int n){
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



//initializers
void Device::initAllLength(){
    qInfo("init all lenfrg");
    //Opens the file called allLengths
    QFile file(":/res/data/allLengths.txt");

    //checks if the file exists and loads it. Handles errors.
    if(!file.exists()) qFatal("Device::initAllLength - ERROR: Specified file not found");
    if(!file.open(QIODevice::ReadOnly)) qFatal("Device::initAllLength - ERROR: Specified file can not be opened");

    QTextStream stream(&file);
    while (!stream.atEnd()){
        int len = stream.readLine().toInt();
//        allLengths.push_back(new SessionLength(len, false));
    }
    file.close();
}

void Device::initAllTypes(){
    //Opens the file
    QFile file(":/res/data/allTypes.txt");

    //checks if the file exists and loads it. Handles errors.
    if(!file.exists()) qFatal("Device::initAllLength - ERROR: Specified file not found");
    if(!file.open(QIODevice::ReadOnly)) qFatal("Device::initAllLength - ERROR: Specified file can not be opened");

    QTextStream stream(&file);
    while (!stream.atEnd()){
        QStringList line = stream.readLine().split(" ");
        float minHz = line[0].toFloat();
        float maxHz = line.size() == 1 ? MAX_HZ : line[1].toFloat();
        CEStype t = line.size() == 2 ? pulse : cycle;
        allTypes.push_back(new SessionType(minHz, maxHz, t));
    }

    file.close();
}




void Device::initSesssionLengths(){
    allLengths.push_back(new SessionLength(25, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_25Min.png" , ":/res/icons/unLit/session_times/icon_25Min.png", ui->session_25min)));
    allLengths.push_back(new SessionLength(45, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_45Min.png" , ":/res/icons/unLit/session_times/icon_45Min.png", ui->session_45min)));
    allLengths.push_back(new SessionLength(180, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_3Hour.png" , ":/res/icons/unLit/session_times/icon_3Hour.png", ui->session_3hr)));

}

void Device::initSessionTypes(){
    allTypes.push_back(new SessionType(0.5, 3, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_alpha.png" , ":/res/icons/unLit/sessions/icon_alpha.png", ui->session_alpha)));
    allTypes.push_back(new SessionType(0.5, 3, cycle, new DisplayIcon(":/res/icons/Lit/sessions/icon_SMR.png" , ":/res/icons/unLit/sessions/icon_SMR.png", ui->session_SMR)));
    allTypes.push_back(new SessionType(2.5, 5, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_Beta.png" , ":/res/icons/unLit/sessions/icon_Beta.png", ui->session_Beta)));
    allTypes.push_back(new SessionType(6, 8, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_100Hz.png" , ":/res/icons/unLit/sessions/icon_100Hz.png", ui->session_100Hz)));

}

void Device::initIcons(){
    initClickableIcons();           // icons[0]
    initOtherIcons();               // icons[1] - [8]
    initSessionLengthIcons();
    initSessionTypeIcons();
}

void Device::initClickableIcons(){
    icons.push_back(new DisplayIcon(":/res/buttons/powerBtn_lit.png", ":/res/buttons/power_Btn_unLit.png", ui->pushButton_Power));
}

void Device::initSessionLengthIcons(){
    for(int i = 0; i < allLengths.size(); i++){
        icons.push_back(allLengths.at(i)->getIcon());
    }

    for(int i = 0; i < allTypes.size(); i++){
        icons.push_back(allTypes.at(i)->getIcon());
    }

    //or create sessionLength objects and pass the new inidividual icons to the class
}

void Device::initSessionTypeIcons(){
    for(int i = 0; i < allTypes.size()-1; i++){
        icons.push_back(allLengths.at(i)->getIcon());
    }
}

void Device::initOtherIcons(){
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_1.png" , ":/res/icons/unLit/colNumbers/icon_1.png",  ui->col_num_1));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_2.png" , ":/res/icons/unLit/colNumbers/icon_2.png",  ui->col_num_2));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_3.png" , ":/res/icons/unLit/colNumbers/icon_3.png",  ui->col_num_3));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_4.png" , ":/res/icons/unLit/colNumbers/icon_4.png",  ui->col_num_4));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_5.png" , ":/res/icons/unLit/colNumbers/icon_5.png",  ui->col_num_5));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_6.png" , ":/res/icons/unLit/colNumbers/icon_6.png",  ui->col_num_6));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_7.png" , ":/res/icons/unLit/colNumbers/icon_7.png",  ui->col_num_7));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_8.png" , ":/res/icons/unLit/colNumbers/icon_8.png",  ui->col_num_8));

}

void Device::resetGraph(){
    for(int i=1; i<=8; i++){
        icons[i]->setIllumState(dim);
    }
}
