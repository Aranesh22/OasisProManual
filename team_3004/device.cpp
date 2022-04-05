#include "device.h"

#include <fstream>
#include <sstream>
#include <string>

#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;


Device::Device(Ui::MainWindow* ui) : ui(ui)
{
    initIcons(); //still needs to be implemented
    battery = new Battery();
    connection = disconnected;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();
    initAllLength();
    initAllTypes();

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




//setters
void Device::turnOn(){
    curUseCase = displayingBattery;
    power = on;
}

void Device::turnOff(){
    power = off;
    curUseCase = blank;
}

void Device::setSession(Session* s){
    curSession = s;
}





//system events
void Device::handleLowBattery(){
//    if(curUseCase == runningSession) curSession->end();
    curUseCase = lowBattery;

}

ConnectionState Device::testForConnection(){
    curUseCase = loadingConnection;
    connection = connected;
    return connection;
}





//user inputs
void Device::handleUpArrow(){
    //check current use case
    //call the right function
    //is there a better approach that avoids if-else spam / switch?
    //yes; declare maps to function pointers (might be too complicated, so for the scope of this project, if-else spam might be fine)
}

void Device::handleDownArrow(){

}

void Device::handlePowerButton(){

}

void Device::handleSave(){

}

void Device::handleCheck(){

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

void Device::prevSesType(){
    int i = indexOf(curSesType)-1;
    if( i < 0 ) i = allTypes.size() - 1;
    curSesType = allTypes[i];
}

void Device::nextSesType() {
    int i = indexOf(curSesType)+1;

    if( i == allTypes.size()) i = allTypes.size() + 1;

    curSesType = allTypes[i];
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





//initializers
void Device::initAllLength(){
    //Opens the file called allLengths
    QFile file(":/res/data/allLengths.txt");

    //checks if the file exists and loads it. Handles errors.
    if(!file.exists()) qFatal("Device::initAllLength - ERROR: Specified file not found");
    if(!file.open(QIODevice::ReadOnly)) qFatal("Device::initAllLength - ERROR: Specified file can not be opened");

    QTextStream stream(&file);
    while (!stream.atEnd()){
        int len = stream.readLine().toInt();
        allLengths.push_back(new SessionLength(len, false));
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

void Device::initIcons(){
    initClickableIcons();
    initSessionLengthIcons();
    initSessionTypeIcons();
}

void Device::initClickableIcons(){

}

void Device::initSessionLengthIcons(){

}

void Device::initSessionTypeIcons(){

}

void Device::initOtherIcons(){

}
