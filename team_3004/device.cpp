#include "device.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;


Device::Device(Ui::MainWindow* ui) : ui(ui)
{

    battery = new Battery();
    connection = disconnected;
    power = off;
    outputtingAudio = false;

    history = new HistoryManager();

    initSesssionLengths();
    initSessionTypes();

    initIcons();

    curSesLength = allLengths[0];
    curSesType = allTypes[0];
    curSession = nullptr;
    curUseCase = blank;

//    test();


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
//    curUseCase = displayingBattery;
    curUseCase = selectSessionLength;
    curSesLength->getIcon()->toggleIllum();
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
    if(curUseCase == selectSessionLength) nextSesLen();
}

void Device::handleDownArrow(){
    if(curUseCase == selectSessionLength) prevSesLen();
}

void Device::handlePowerButton(){

}

void Device::handleSave(){

}

void Device::handleCheck(){

}

void Device::nextSesLen(){
    int i = indexOf(curSesLength)+1;
    allLengths[i-1]->getIcon()->toggleIllum();

    if( i == allLengths.size() ) i = 0;
    curSesLength = allLengths[i];

    curSesLength->getIcon()->toggleIllum();
}

void Device::prevSesLen(){
    int i = indexOf(curSesLength)-1;
    allLengths[i+1]->getIcon()->toggleIllum();

    if( i < 0 ) i = allLengths.size() - 1;
    curSesLength = allLengths[i];

    curSesLength->getIcon()->toggleIllum();
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
    DisplayIcon* powerButton = new DisplayIcon(":/res/buttons/powerBtn_lit.png", ":/res/buttons/power_Btn_Lit.png", ui->pushButton_Power);
    icons.push_back(powerButton);
}

void Device::initSessionLengthIcons(){
    for(int i = 0; i < allLengths.size()-1; i++){
        icons.push_back(allLengths.at(i)->getIcon());
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


void Device::test(){
    curSesLength->getIcon()->toggleIllum();
}
