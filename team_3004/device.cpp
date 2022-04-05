#include "device.h"

#include <fstream>
#include <sstream>
#include <string>

#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;


Device::Device(Ui::MainWindow* ui) : ui(ui)
{
    initButtons(); //still needs to be implemented
    battery = new Battery();
    connection = disconnected;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();
    curSession = nullptr;
    curUseCase = blank;
    initAllLength();
    initAllTypes();
    curSesLength = allLengths[0];
    curSesType = allTypes[0];


}

Device::Device(){
    qInfo() << "boring";
}

//Ui::MainWindow Device::testing(){

//    QIcon x = QIcon(":/res/buttons/powerBtn_lit.png" );

////    ui->pushButton_8->setIcon(x);
//}

//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}
UseCase Device::getCurUseCase() {return curUseCase;}
vector<DisplayIcon*> Device::getIcons(){return icons;}

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

void Device::initButtons(){
/*  for file in /res/icons/Lit: initIcon(file)
 *  for file in /res/icons: initIcon(file)
 *  for file in /res/buttons/: initButton(file);
 *  NOTE: this seems like a good instance of a STRATEGY DESIGN PATTERN
 */

    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_1.png" , ":/res/icons/unLit/colNumbers/icon_1.png",  ui->pushButton_8));

}

/*
void Device::initIcon(litPath){
    // let dim = find same file but unlit
        // if not found, display error
    allButtons.push_back(new DisplayIcon(lit, dim, findUiComponent(litPath) ));
}

void Device::findUiComponent(path){
    return ui->path;
}
*/
