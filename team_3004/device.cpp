#include "device.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QTime>
#include <QElapsedTimer>

#include <unistd.h>
#include <sstream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QFile>
#include <QTextStream>


using namespace std;


Device::Device(Ui::MainWindow* ui) : ui(ui)
{

    battery = new Battery();
    connection = none;
    power = off;
    outputtingAudio = false;

    ui->battery_progressBar->setValue(battery->getBatteryPercent());


    history = new HistoryManager();

    initSessionLengths();
    initSessionTypes();
    initIcons();

    curSesLength = allLengths[0];
    curSesType = allTypes[0];
    curSession = nullptr;
    curUseCase = blank;

    sysCycleTimer = new QTimer(this);
    connect(sysCycleTimer, SIGNAL(timeout()), this, SLOT(runSysCycle()));

    displayBatteryTimer = new QTimer(this);
    connect(displayBatteryTimer, SIGNAL(timeout()), this, SLOT(displayBatteryLevel()));

    sessionTimer = new QTimer(this);
    connect(sessionTimer, SIGNAL(timeout()), this, SLOT(elapseSession()));

}


//getters
PowerState Device::getPower(){return power;}
Battery* Device::getBattery(){return battery;}
bool Device::isOutputtingAudio(){return outputtingAudio;}
HistoryManager* Device::getHistory(){return history;}
Session* Device::getCurSession(){return curSession;}
UseCase Device::getCurUseCase() {return curUseCase;}
vector<DisplayIcon*> Device::getIcons(){return icons;}


void Device::runSysCycle(){
    drainBattery();
    testForConnection();
}


//system events
void Device::handleLowBattery(){
    qInfo("Low battery detected");
    if(battery->getBatteryPercent() == 0) turnOff();
    if(curUseCase == runningSession) endSession();
    curUseCase = blank; //prevents user editing data
    displayBatteryLevel();
}

void Device::drainBattery(){
    //see defions.h for more info on MAX_DRAIN and MIN_DRAIN

    /*
     * The step variable determines how every session maps from MAX_DRAIN to MIN_DRAIN
     * To evenly split every intensity from MAX_DRAIN (4) to MIN_DRAIN (3.33)
     * We need to subtract 3.33 from 4
     * And divide the output of the above by 8
     *
     * This all assumes there is a session currently running. If there isn't, we just treat the program as if it were on the lowest intensity.
     * Likewise, if the current session is paused due to a disconnect, we treat it like it had the lowest intensity.
     */

    float step = (MAX_DRAIN - MIN_DRAIN) / MAX_INTENSITY;
    float drained = (curSession == nullptr || curSession->isPaused()) ? MIN_DRAIN : MIN_DRAIN + step * (curSession->getCurIntensity() - 1);
    float remaining = battery->drain(drained);

    if(remaining <= 15) handleLowBattery();
    ui->battery_progressBar->setValue(battery->getBatteryPercent());
    qInfo("\tDrain battery - drained = %f, remaining = %f", drained, remaining);

}


void Device::chargeBattery(){
    battery->charge(ui->chargeBy->value());
      ui->battery_progressBar->setValue(battery->getBatteryPercent());

}

void Device::testForConnection(){
    qInfo() << "\tTest connection";

    if(connection == none){
        qInfo("No Connection detected!");
        if(curUseCase == runningSession) pauseSession();
        displayConnection();
    }

    // equivalent to if(connecion != none && curUseCase == runningSession && curSession->isPaused() )
    if(curUseCase == pausedSession && connection != none){
        qInfo("Unpausing session");
        unpauseSession();
    }
}

void Device::displayConnection(){
    qInfo("DisplayConection");

    resetGraph();

    icons[ icons.size()-3 ] -> setIllumState(flashing);
    icons[ icons.size()-4 ] -> setIllumState(flashing);

    if(connection == none){
        icons[7]->setIllumState(flashing);
        icons[8]->setIllumState(flashing);
    }

    else{
        icons[icons.size()-1]->setIllumState(lit);
        icons[icons.size()-2]->setIllumState(lit);
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
    icons[ icons.size()-3 ] -> setIllumState(dim);
    icons[ icons.size()-4 ] -> setIllumState(lit);
//    curSesType->getCESIcon()->setIllumState(lit);
    resetGraph();
}




//user inputs
void Device::handleUpArrow(){
    if(curUseCase == selectingSession) nextSesType();
    else if(curUseCase == runningSession) incIntensity();
}

void Device::handleDownArrow(){
    if(curUseCase == selectingSession) prevSesType();
    else if(curUseCase == runningSession) decIntensity();
}

void Device::handlePowerButton(){
    if(power == off) turnOn();
    else if(curUseCase == selectingSession) nextSesLen();
    else if (curUseCase == runningSession) turnOff();
//    else if (curUseCase == runningSession) displaySoftOn();
}


void Device::displayBatteryLevel(){
    qInfo("Displaying battery");

    for(int i = 1; i <= battery->getBatteryLevel(); i++){
        if(battery->getBatteryLevel() > 2) icons[i]->setIllumState(lit);
        if(battery->getBatteryLevel() <= 2) icons[i]->setIllumState(flashing);
    }

    delayBy(2);
    resetGraph();


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
    int i = indexOf(curSesType)-1;
    allTypes[i+1]->getIcon()->toggleIllum();

    if( i < 0 ) i = allTypes.size() - 1;
    curSesType = allTypes[i];

    allTypes[i]->getIcon()->toggleIllum();

}

void Device::nextSesType() {
    int i = indexOf(curSesType)+1;
    allTypes[i-1]->getIcon()->toggleIllum();
    allTypes[i-1]->getCESIcon()->toggleIllum();

    if( i == allTypes.size() ) i = 0;

    curSesType = allTypes[i];
    allTypes[i]->getIcon()->toggleIllum();
    allTypes[i]->getCESIcon()->toggleIllum();
}

vector<QString> Device::uploadSaveSession() {
    if(curUseCase != runningSession){
        vector<QString> x;
        return x;
    }

    qInfo("Saved Session");
    history->SaveSession(curSession);
    history->getSessions();
    //PRINT OUT THE VECTORS IMAGES PATHS

    vector<Session*> allSessions = history->getSessions();
    vector<DisplayIcon*> icons;

    SessionLength* sl = curSession->getLength();
    SessionType* st = curSession->getType();

    QString curInt = QString::number(curSession->getCurIntensity());

    vector<QString> data;
    data.push_back(curInt);
    data.push_back((sl->getIcon())->getPathAt(dim));
    data.push_back((st->getIcon())->getPathAt(dim));

    return data;


    /*
    for (Session* s : allSessions) {
        SessionLength* sl = s->getLength();
        SessionType* st = s->getType();
        qInfo() << s->getCurIntensity();

        qInfo() << (sl->getIcon())->getPathAt(lit);
        qInfo() << (st->getIcon())->getPathAt(lit);
    }
    */

}

void Device::startSession(){
    //test and display connection
    testForConnection();
    displayConnection();
    if(connection == none){
        qInfo("Can not start lesson - no ear clip connection");
        return;
    }

    //flash for 5 seconds
    curUseCase = blank; //prevents user from editing data while button is flashing
    curSesType->getIcon()->setIllumState(flashing);
    delayBy(5);
    curSesType->getIcon()->setIllumState(lit);

    //session is now running
    curSession = new Session(curSesLength, curSesType);
    sessionTimer->start(SESSION_INTERVAL);
    curUseCase = runningSession;
    icons[1]->setIllumState(flashing);
}

void Device::endSession(){
    qInfo("Ending session");

    sessionTimer->stop();

    //soft off
    curUseCase = blank; //prevens user from editing data during soft off
    for(int i=curSession->getCurIntensity(); i>=1; i--){
        icons[i]->setIllumState(dim);
        delayBy(1);
    }

    curSession = nullptr;
}

void Device::displaySoftOn(){
    qInfo("DISPLAY SOFT ON");
    resetGraph();

    //NEEDS TO HANDLE UP/DOWN ARROW INTERRUPTION

    curUseCase = softOn;
    for(int i=1; i<=curSession->getCurIntensity(); i++){
        icons[i]->setIllumState(lit);
        if(curUseCase == softOn) delayBy(1);
    }

    curUseCase = runningSession;
}

void Device::incIntensity(){
    icons[curSession->getCurIntensity() ] -> setIllumState(lit);
    curSession->incInten();
    icons[curSession->getCurIntensity() ] -> setIllumState(flashing);
}

void Device::decIntensity(){
    if(curSession->getCurIntensity() != MIN_INTENSITY)icons[curSession->getCurIntensity() ] -> setIllumState(dim);
    curSession->decInten();
    icons[curSession->getCurIntensity()] -> setIllumState(flashing);
}


//setters
void Device::turnOn(){
    power = on;
    //turn on the power button
    icons[0]->toggleIllum();

    //display battery
    curUseCase = displayingBattery;
    displayBatteryLevel();
    curUseCase = selectingSession;

    //lights up the first session length, session type, and its respective CEStype
    curSesLength->getIcon()->toggleIllum();
    curSesType->getIcon()->toggleIllum();
    curSesType->getCESIcon()->toggleIllum();

    //starts the timers
    sysCycleTimer->start(SYSCYCLE_INTERVAL);
    displayBatteryTimer->start(DISPLAY_BATTERY_INTERVAL);

}

void Device::turnOff(){

    /*
    QElapsedTimer timerTOff;
    timerTOff.start();
    qInfo("%"timerTOff.elapsed);
    */

    // /home/student/Desktop/COMP3004/Project/comp3004Project/team_3004/userData.txt
    // :/res/userData/userData.txt

    /* Try and open a file for output */
    qInfo("Hello");
    /*
    QString outputFilename = ":/res/userData/userData.txt";
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);


    if(!outputFile.isOpen()){
        qDebug() << "- Error, unable to open" << outputFilename << "for output";
        return;
    }


    QTextStream outStream(&outputFile);


    outStream << "Victory!\n";


    outputFile.close();
    */


    sysCycleTimer->stop();
    displayBatteryTimer->stop();

    //if a session is running, then end it
    if(curSession != nullptr) endSession();
    power = off;
    curUseCase = blank;
    //clearHmTable();

    for(DisplayIcon* di : icons){
        di->setIllumState(dim);
    }

    curUseCase = blank;
    battery->powerOff();

}

void Device::setSession(Session* s){
    curSession = s;
}

void Device::clearHmTable() {


    for (int i=0;i< (ui->tableWidget->rowCount());i++) {
            qInfo("hellooooooooooooooooo");
            for (int j=0;j< (ui->tableWidget->columnCount()) ;j++) {
                QTableWidgetItem *item =  ui->tableWidget->item(i,j);
                qInfo("LINDS JOIN BACKKKKKKKKKKK");
                item->setIcon(QIcon(":/res/icons/unLit/black.png"));

            }
        }


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



//ializers
void Device::initAllLength(){
    //Opens the file called allLengths
    QFile file(":/res/data/allLengths.txt");

    //checks if the file exists and loads it. Handles errors.
    if(!file.exists()) qFatal("Device::AllLength - ERROR: Specified file not found");
    if(!file.open(QIODevice::ReadOnly)) qFatal("Device::AllLength - ERROR: Specified file can not be opened");

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




void Device::initSessionLengths(){
    allLengths.push_back(new SessionLength(25, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_25Min.png" , ":/res/icons/unLit/session_times/icon_25Min.png", ui->session_25min)));
    allLengths.push_back(new SessionLength(45, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_45Min.png" , ":/res/icons/unLit/session_times/icon_45Min.png", ui->session_45min)));
    allLengths.push_back(new SessionLength(180, false, new DisplayIcon( ":/res/icons/Lit/sessionTimes/icon_3Hour.png" , ":/res/icons/unLit/session_times/icon_3Hour.png", ui->session_3hr)));
    //missing the custom
}

void Device::initSessionTypes(){
    allTypes.push_back(new SessionType(0.5, 3, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_alpha.png" , ":/res/icons/unLit/sessions/icon_alpha.png", ":/res/icons/gifs/sessionTypes/icon_alpha.gif", ui->session_alpha), new DisplayIcon(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ":/res/icons/gifs/icon_shortPulse_CESsession.gif", ui->shortPulse_CESsession)));
    allTypes.push_back(new SessionType(0.5, 3, cycle, new DisplayIcon(":/res/icons/Lit/sessions/icon_SMR.png" , ":/res/icons/unLit/sessions/icon_SMR.png", ":/res/icons/gifs/sessionTypes/icon_SMR.gif", ui->session_SMR), new DisplayIcon(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ":/res/icons/gifs/icon_shortPulse_CESsession.gif", ui->shortPulse_CESsession)));
    allTypes.push_back(new SessionType(2.5, 5, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_Beta.png" , ":/res/icons/unLit/sessions/icon_Beta.png", ":/res/icons/gifs/sessionTypes/icon_Beta.gif",  ui->session_Beta), new DisplayIcon(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ":/res/icons/gifs/icon_shortPulse_CESsession.gif", ui->shortPulse_CESsession)));
    allTypes.push_back(new SessionType(6, 8, pulse, new DisplayIcon(":/res/icons/Lit/sessions/icon_100Hz.png" , ":/res/icons/unLit/sessions/icon_100Hz.png", ":/res/icons/gifs/sessionTypes/icon_100Hz.gif", ui->session_100Hz), new DisplayIcon(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ":/res/icons/gifs/icon_shortPulse_CESsession.gif", ui->shortPulse_CESsession)));

}

void Device::initIcons(){
    initPowerIcon();           // icons[0]
    initGraphIcons();          // icons[1] - [8]
    initSessionIcons();        // icons[9] - icons[16]
    initOtherIcons();          // icons[17] - [20]
}

void Device::initPowerIcon(){
    icons.push_back(new DisplayIcon(":/res/buttons/powerBtn_lit.png", ":/res/buttons/power_Btn_unLit.png", ui->pushButton_Power));
}

void Device::initSessionIcons(){
    for(int i = 0; i < allLengths.size(); i++){
        icons.push_back(allLengths.at(i)->getIcon());
    }

    for(int i = 0; i < allTypes.size(); i++){
        icons.push_back(allTypes.at(i)->getIcon());
    }

    //or create sessionLength objects and pass the new inidividual icons to the class
}

void Device::initOtherIcons(){
    icons.push_back(new DisplayIcon(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ":/res/icons/gifs/icon_shortPulse_CESsession.gif", ui->shortPulse_CESsession));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/icon_dutyCycle_CESsession.png" , ":/res/icons/unLit/icon_dutyCycle_CESsession.png", ":/res/icons/gifs/icon_dutyCycle_CESsession.gif", ui->dutyCycle_CESsession));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/icon_LeftCESchannel.png" , ":/res/icons/unLit/icon_LeftCESchannel.png", ui->left_CESchannel));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/icon_RightCESchannel.png" , ":/res/icons/unLit/icon_RightCESchannel.png", ui->right_CESchannel));

}

void Device::initGraphIcons(){
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_1.png" , ":/res/icons/unLit/colNumbers/icon_1.png", ":/res/icons/gifs/icon_1.gif", ui->col_num_1));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_2.png" , ":/res/icons/unLit/colNumbers/icon_2.png", ":/res/icons/gifs/icon_2.gif",   ui->col_num_2));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_3.png" , ":/res/icons/unLit/colNumbers/icon_3.png", ":/res/icons/gifs/icon_3.gif",   ui->col_num_3));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_4.png" , ":/res/icons/unLit/colNumbers/icon_4.png", ":/res/icons/gifs/icon_4.gif",   ui->col_num_4));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_5.png" , ":/res/icons/unLit/colNumbers/icon_5.png", ":/res/icons/gifs/icon_5.gif",   ui->col_num_5));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_6.png" , ":/res/icons/unLit/colNumbers/icon_6.png", ":/res/icons/gifs/icon_6.gif",   ui->col_num_6));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_7.png" , ":/res/icons/unLit/colNumbers/icon_7.png", ":/res/icons/gifs/icon_7.gif",   ui->col_num_7));
    icons.push_back(new DisplayIcon(":/res/icons/Lit/colNumber/icon_8.png" , ":/res/icons/unLit/colNumbers/icon_8.png", ":/res/icons/gifs/icon_8.gif",   ui->col_num_8));




}

void Device::resetGraph(){
    for(int i=1; i<=8; i++){
        icons[i]->setIllumState(dim);
    }
}


void Device::elapseSession(){
    int elapsed = curSession->elapseMinute();
    qInfo("\tElapse session - time elapsed: %i", elapsed);

    if(elapsed == curSession->getLength()->getDurationMins() ){
        qInfo("Duration of the session has ended");
        endSession();
        curUseCase = selectingSession;
    }
}

void Device::pauseSession(){
    curSession->pause();
    sessionTimer->stop();
    curUseCase = pausedSession;
}

void Device::unpauseSession(){
    curSession->unpause();
    curUseCase = runningSession;

    for(int i=1; i<curSession->getCurIntensity(); i++) icons[i]->setIllumState(lit);
    icons[curSession->getCurIntensity() ] -> setIllumState(flashing);

    sessionTimer->start(SESSION_INTERVAL);
}

void Device::simDisconnection(){
    connection = none;
}

void Device::simReconnect(){
    connection = okay;
}
