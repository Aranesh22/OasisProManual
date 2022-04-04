#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

#include "displayicon.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    device = new Device(ui);

    indexSessionTimeIcon = 0;
    indexSessionIcon = 0;
    indexIntensityIcon = 0;

    initalizeVectors();
    connect(ui->pushButton_8, &QPushButton::pressed, this, &MainWindow::show_power);
    connect(ui->pushButton_Up, &QPushButton::pressed, this, &MainWindow::moveNext);
    connect(ui->pushButton_Down, &QPushButton::pressed, this, &MainWindow::moveBack);
    connect(ui->pushButton_Select, &QPushButton::pressed, this, &MainWindow::makeSelection);

    sessionTimer = new QTimer(this);

    sessionTimer->setSingleShot(true);
    connect(sessionTimer, &QTimer::timeout, this, &MainWindow::sessionTimeout);

}



//cahnges power display button between it's on and off state
void MainWindow::show_power(){

    device->getPower() ? device->turnOn() : device->turnOff();

    QIcon x = QIcon(!device->getPower() ? ":/res/buttons/powerBtn_lit.png" : ":/res/buttons/power_Btn_unLit.png");

    ui->pushButton_8->setIcon(x);

    if(device->getPower() == on){
        show_battery();
        delayBy(1);
        uniformUiChange(true);
        delayBy(1);
    }
    if(device->getPower() == off)
        uniformUiChange(false);




    //sets the session times to white
//    if(!device->getPower())
//        initForSelection(sessionTimeIconVector);
//initForSelection(graphIconVector);


}

//have a check to ensure that the battery is infact ON before executing
//uses enumeration
//move the selection forward
void MainWindow::moveNext(){
    if(device->getPower() != on)
        return;
    qInfo("up arrow");
    if(device->getCurUseCase() == selectSessionLength)
        incrementUiSelection(sessionTimeIconVector, indexSessionTimeIcon);
         //call function from device to increment the session time selection

    if(device->getCurUseCase() == selectSession)
        incrementUiSelection(sessionIconVector, indexSessionIcon);
        //call function from device to increment the session selection

    if(device->getCurUseCase() == runningSession){
        incrementUiSelection(graphIconVector, indexIntensityIcon);
        device->getCurSession()->incInten();
    }

// incrementUiSelection(graphIconVector, indexIntensityIcon);
}


//moves the selection to the previous
void MainWindow::moveBack(){
    if(device->getPower() != on)
        return;
    qInfo("down arrow");
    if(device->getCurUseCase() == selectSessionLength)
        decrementUiSelection(sessionTimeIconVector, indexSessionTimeIcon);
        //call function from device to decrement the session time selection

    if(device->getCurUseCase() == selectSession)
        decrementUiSelection(sessionIconVector, indexSessionIcon);
        //call function from device to decrement the session selection

    if(device->getCurUseCase() == runningSession){
        decrementUiSelection(graphIconVector, indexIntensityIcon);
        device->getCurSession()->decInten();
    }
//         decrementUiSelection(graphIconVector, indexIntensityIcon);/
}

void MainWindow::makeSelection() {
    if(device->getPower() != on)
        return;
    qInfo("Select");


    //will be called only once the connection test is verified
    sessionTimer->start(5000);


//advance to next use case
    /* i.e.
     * selectSessionLength > selectSession
     * selectSession > runningSession

*/
    //would then call initForSelection()
}


void MainWindow::sessionTimeout(){
    qInfo() << "Session completed! - shutting down";
    show_power();

}

void MainWindow::deadBatteryUI(){
    qInfo() << "LOW BATTERY";
//fix this lol
    swapIcon(graphIconVector[0]->state ? graphIconVector[0]->activePath : graphIconVector[0]->inactivePath, graphIconVector[0]->uiElement);
    graphIconVector[0]->state = !graphIconVector[0]->state;



}



void MainWindow::incrementUiSelection(QVector<Button*> iconArray, int& index){
//    if(!device->getCurUseCase()== runningSession)
//        graphDisplay( index == iconArray.length()-1 ? index = 0 : index++);
//        return;
    swapIcon(iconArray[index]->state ? iconArray[index]->inactivePath : iconArray[index]->activePath, iconArray[index]->uiElement);
    iconArray[index]->state = !iconArray[index]->state;

    index == iconArray.length()-1 ? index = 0 : index++;

    swapIcon(iconArray[index]->state ? iconArray[index]->inactivePath : iconArray[index]->activePath, iconArray[index]->uiElement);
    iconArray[index]->state = !iconArray[index]->state;
}

void MainWindow::decrementUiSelection(QVector<Button*> iconArray, int& index){
   //fix this
//    graphDisplay(index == 0 ? index = iconArray.length()-1 : index--);
//    return;

    swapIcon(iconArray[index]->state ? iconArray[index]->inactivePath : iconArray[index]->activePath, iconArray[index]->uiElement);
    iconArray[index]->state = !iconArray[index]->state;

    index == 0 ? index = iconArray.length()-1 : index--;

    swapIcon(iconArray[index]->state ? iconArray[index]->inactivePath : iconArray[index]->activePath, iconArray[index]->uiElement);
    iconArray[index]->state = !iconArray[index]->state;
}




//Found on stack overflow - look more into this function and prob modify it
//https://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
void MainWindow::delayBy(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



void MainWindow::graphDisplay(int curLevel){
    qInfo() << "graph display";
    int i=0;
//    for(int i = 0; i <= curLevel; i++){
//        changePixmap(graphIconVector[i]->activePath, graphIconVector[i]->uiElement);
//       graphIconVector[i]->state = true;
//    }
    while(i< graphIconVector.length()){
        if(i < curLevel){
            swapIcon(graphIconVector[i]->activePath, graphIconVector[i]->uiElement);
           graphIconVector[i]->state = true;
        }else{
            swapIcon(graphIconVector[i]->inactivePath, graphIconVector[i]->uiElement);
           graphIconVector[i]->state = false;
        }
        i++;
    }

}

void MainWindow::show_battery(){
    for(int i = 0; i <= device->getBattery()->getBatteryLevel()-1; i++){
        swapIcon(graphIconVector[i]->activePath, graphIconVector[i]->uiElement);
    }
    if(device->getCurUseCase() == lowBattery){
        qInfo() << "low battery";
        //do something
    }
    if(device->getCurUseCase() == deadBattery){
        qInfo() << "dead battery";
        //graph blinks a single red bar and the device turns off

        device->turnOff();
        uniformUiChange(false);
    }
}



//changes the pixmap image for a QLabel
void MainWindow::swapIcon(QString iconPath, QLabel* uiLabel){
    QPixmap newIcon = QPixmap(iconPath);
    uiLabel->setPixmap(newIcon);
}



void MainWindow::initForSelection(QVector<Button*> iconArray){
    for (int i = 1; i < iconArray.length(); i++){
        swapIcon(iconArray[i]->inactivePath, iconArray[i]->uiElement);
        iconArray[i]->state = false;
    }
}


void MainWindow::uniformUiChange(bool newState){

//Connection state
    for (int i = 0; i < connectionIconVector.length(); i++) {
        connectionIconVector[i]->state = newState;
        swapIcon(connectionIconVector[i]->state ? connectionIconVector[i]->activePath : connectionIconVector[i]->inactivePath, connectionIconVector[i]->uiElement);
    }

//session times
    for (int i = 0; i < sessionTimeIconVector.length(); i++){
        sessionTimeIconVector[i]->state = newState;
        swapIcon(newState ? sessionTimeIconVector[i]->activePath : sessionTimeIconVector[i]->inactivePath, sessionTimeIconVector[i]->uiElement);
    }

//session types
    for (int i = 0; i < sessionIconVector.length(); i++){
        sessionIconVector[i]->state = newState;
        swapIcon(sessionIconVector[i]->state ? sessionIconVector[i]->activePath : sessionIconVector[i]->inactivePath, sessionIconVector[i]->uiElement);
    }

//column numbers
    for (int i = 0; i < graphIconVector.length(); i++){
        graphIconVector[i]->state = newState;
        swapIcon(graphIconVector[i]->state ? graphIconVector[i]->activePath : graphIconVector[i]->inactivePath, graphIconVector[i]->uiElement);
    }
}


void MainWindow::initalizeVectors(){

    //graph
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_1.png" , ":/res/icons/unLit/colNumbers/icon_1.png",  ui->col_num_1));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_2.png" , ":/res/icons/unLit/colNumbers/icon_2.png",  ui->col_num_2));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_3.png" , ":/res/icons/unLit/colNumbers/icon_3.png",  ui->col_num_3));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_4.png" , ":/res/icons/unLit/colNumbers/icon_4.png",  ui->col_num_4));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_5.png" , ":/res/icons/unLit/colNumbers/icon_5.png",  ui->col_num_5));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_6.png" , ":/res/icons/unLit/colNumbers/icon_6.png",  ui->col_num_6));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_7.png" , ":/res/icons/unLit/colNumbers/icon_7.png",  ui->col_num_7));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_8.png" , ":/res/icons/unLit/colNumbers/icon_8.png",  ui->col_num_8));

    //Session times
    sessionTimeIconVector.push_back(new Button( ":/res/icons/Lit/sessionTimes/icon_25Min.png" , ":/res/icons/unLit/session_times/icon_25Min.png", ui->session_25min));
    sessionTimeIconVector.push_back(new Button(":/res/icons/Lit/sessionTimes/icon_45Min.png" , ":/res/icons/unLit/session_times/icon_45Min.png", ui->session_45min));
    sessionTimeIconVector.push_back(new Button( ":/res/icons/Lit/sessionTimes/icon_3Hour.png" , ":/res/icons/unLit/session_times/icon_3Hour.png", ui->session_3hr));
    sessionTimeIconVector.push_back(new Button( ":/res/icons/Lit/sessionTimes/icon_customTime.png" ,  ":/res/icons/unLit/session_times/icon_customTime.png",  ui->session_custom));

    //sessions
    sessionIconVector.push_back(new Button(":/res/icons/Lit/sessions/icon_alpha.png" , ":/res/icons/unLit/sessions/icon_alpha.png", ui->session_alpha));
    sessionIconVector.push_back(new Button(":/res/icons/Lit/sessions/icon_SMR.png" , ":/res/icons/unLit/sessions/icon_SMR.png", ui->session_SMR));
    sessionIconVector.push_back(new Button(":/res/icons/Lit/sessions/icon_Beta.png" , ":/res/icons/unLit/sessions/icon_Beta.png", ui->session_Beta));
    sessionIconVector.push_back(new Button(":/res/icons/Lit/sessions/icon_100Hz.png" , ":/res/icons/unLit/sessions/icon_100Hz.png", ui->session_100Hz));

    // connection icon
    connectionIconVector.push_back(new Button(":/res/icons/Lit/icon_dutyCycle_CESsession.png" , ":/res/icons/unLit/icon_dutyCycle_CESsession.png", ui->dutyCycle_CESsession));
    connectionIconVector.push_back(new Button(":/res/icons/Lit/icon_shortPulse_CESsession.png" , ":/res/icons/unLit/icon_shortPulse_CESsession.png", ui->shortPulse_CESsession));
    connectionIconVector.push_back(new Button(":/res/icons/Lit/icon_LeftCESchannel.png" , ":/res/icons/unLit/icon_LeftCESchannel.png", ui->left_CESchannel));
    connectionIconVector.push_back(new Button(":/res/icons/Lit/icon_RightCESchannel.png" , ":/res/icons/unLit/icon_RightCESchannel.png",  ui->right_CESchannel));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    icon = device->getIcons()[0];
    swapIcon(icon->getPath() , icon->getUiElement() );
}
