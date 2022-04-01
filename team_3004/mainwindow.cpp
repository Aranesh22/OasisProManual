#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton_8, &QPushButton::pressed, this, &MainWindow::show_power);
    connect(ui->pushButton_Up, &QPushButton::pressed, this, &MainWindow::moveNext);
    connect(ui->pushButton_Down, &QPushButton::pressed, this, &MainWindow::moveBack);
    connect(ui->pushButton_Select, &QPushButton::pressed, this, &MainWindow::makeSelection);

    // flags (prob will need to discuss what to do with these )


    device = new Device();
    indexSessionTimeIcon = 0;
    indexSessionIcon = 0;
    indexIntensityIcon = 0;

    initalizeVectors();

}



void MainWindow::initalizeVectors(){

    //graph
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_8.png" , ":/res/icons/unLit/colNumbers/icon_8.png",  ui->col_num_8));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_7.png" , ":/res/icons/unLit/colNumbers/icon_7.png",  ui->col_num_7));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_6.png" , ":/res/icons/unLit/colNumbers/icon_6.png",  ui->col_num_6));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_5.png" , ":/res/icons/unLit/colNumbers/icon_5.png",  ui->col_num_5));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_4.png" , ":/res/icons/unLit/colNumbers/icon_4.png",  ui->col_num_4));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_3.png" , ":/res/icons/unLit/colNumbers/icon_3.png",  ui->col_num_3));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_2.png" , ":/res/icons/unLit/colNumbers/icon_2.png",  ui->col_num_2));
    graphIconVector.push_back(new Button(":/res/icons/Lit/colNumber/icon_1.png" , ":/res/icons/unLit/colNumbers/icon_1.png",  ui->col_num_1));

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

//have a check to ensure that the battery is infact ON before executing
//uses enumeration
//move the selection forward
void MainWindow::moveNext(){
    qInfo("moving Next");

//    if(device->curUseCase()==selectSession)

    incrementSessionTime();


}



void MainWindow::incrementSessionTime(){
   qInfo() << "Increment !";
//   int index = 0;
    //turn off previous highlighting

   indexSessionTimeIcon == sessionTimeIconVector.length()-1 ? indexSessionTimeIcon = 0 : indexSessionTimeIcon++;
   sessionTimeIconVector[indexSessionTimeIcon];
   qInfo() << indexSessionTimeIcon;

//highlight new icon
   changePixmap(sessionTimeIconVector[indexSessionTimeIcon]->state ? sessionTimeIconVector[indexSessionTimeIcon]->inactivePath : sessionTimeIconVector[indexSessionTimeIcon]->activePath, sessionTimeIconVector[indexSessionTimeIcon]->uiElement);
   sessionTimeIconVector[indexSessionTimeIcon]->state = !sessionTimeIconVector[indexSessionTimeIcon]->state;

}

void MainWindow::decrementSessionTime(){

}

//moves the selection to the previous
void MainWindow::moveBack(){
    qInfo("moving Back");
}

void MainWindow::makeSelection() {
    qInfo("Select");
}


//cahnges power display button between it's on and off state
void MainWindow::show_power(){

    device->getPower() ? device->turnOn() : device->turnOff();

    QIcon x = QIcon(!device->getPower() ? ":/res/buttons/powerBtn_lit.png" : ":/res/buttons/power_Btn_unLit.png");

    ui->pushButton_8->setIcon(x);

    if(!device->getPower()){
        show_battery();
        delayBy(1);
    }
    lit();

}


//Found on stack overflow - look more into this function and prob modify it
//https://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
void MainWindow::delayBy(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::show_battery(){
//Prob find a cleaner way to do this
    for(int i = 1; i <= device->getBattery()->getBatteryLevel(); i++){

        if(i == 1)
            changePixmap(":/res/icons/Lit/colNumber/icon_1.png", ui->col_num_1);

        if(i == 2)
            changePixmap(":/res/icons/Lit/colNumber/icon_2.png", ui->col_num_2);

        if(i == 3)
            changePixmap(":/res/icons/Lit/colNumber/icon_3.png", ui->col_num_3);

        if(i == 4)
            changePixmap(":/res/icons/Lit/colNumber/icon_4.png", ui->col_num_4);

        if(i == 5)
            changePixmap(":/res/icons/Lit/colNumber/icon_5.png", ui->col_num_5);

        if(i == 6)
            changePixmap(":/res/icons/Lit/colNumber/icon_6.png", ui->col_num_6);

        if(i == 7)
            changePixmap(":/res/icons/Lit/colNumber/icon_7.png", ui->col_num_7);

        if(i == 8)
            changePixmap(":/res/icons/Lit/colNumber/icon_8.png", ui->col_num_8);
    }
}

// <QLabel* Key> < List value > containing if the icon is lit or not + it's state


// lights up all the icons to their powered on state
//Might need flags to show if an icon is lit or not
void MainWindow::lit(){

//store in a key value pair??
//    icon_ALL_Lit = !icon_ALL_Lit;

    for (int i = 0; i < connectionIconVector.length(); i++) {
        changePixmap(connectionIconVector[i]->state ? connectionIconVector[i]->inactivePath : connectionIconVector[i]->activePath, connectionIconVector[i]->uiElement);
        connectionIconVector[i]->state = !connectionIconVector[i]->state;
    }

 //session times
    for (int i = 0; i < sessionTimeIconVector.length(); i++){
        changePixmap(sessionTimeIconVector[i]->state ? sessionTimeIconVector[i]->inactivePath : sessionTimeIconVector[i]->activePath, sessionTimeIconVector[i]->uiElement);
        sessionTimeIconVector[i]->state = !sessionTimeIconVector[i]->state;
    }

    //session types
    for (int i = 0; i < sessionIconVector.length(); i++){
        changePixmap(sessionIconVector[i]->state ? sessionIconVector[i]->inactivePath : sessionIconVector[i]->activePath, sessionIconVector[i]->uiElement);
        sessionIconVector[i]->state = !sessionIconVector[i]->state;
    }

//column numbers
    for (int i = 0; i < graphIconVector.length(); i++){
        changePixmap(graphIconVector[i]->state ? graphIconVector[i]->inactivePath : graphIconVector[i]->activePath, graphIconVector[i]->uiElement);
        graphIconVector[i]->state = !graphIconVector[i]->state;
    }
}

//changes the pixmap image for a QLabel
void MainWindow::changePixmap(QString iconPath, QLabel* uiLabel){
    QPixmap newIcon = QPixmap(iconPath);
    uiLabel->setPixmap(newIcon);
}


void MainWindow::unLit(){

}



MainWindow::~MainWindow()
{
    delete ui;
}

