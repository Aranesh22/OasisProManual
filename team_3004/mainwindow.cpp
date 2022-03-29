#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    powerisOn = false;

    connect(ui->pushButton_8, &QPushButton::pressed, this, &MainWindow::show_power);


    // flags (prob will need to discuss what to do with these )
    icon_ALL_Lit = false;
    dutyCycle_CESsession_icon_lit = false;
    shortPulse_CESsession_icon_lit = false;
//    bool
    battery = new Battery();

}


//cahnges power display button between it's on and off state
void MainWindow::show_power(){

    qInfo("changing power display");
    QIcon x = QIcon(powerisOn ? ":/res/buttons/powerBtn_lit.png" : ":/res/buttons/power_Btn_unLit.png");

    ui->pushButton_8->setIcon(x);

    if(powerisOn){
        show_battery();
        delayBy(2);
    }
    lit();
    powerisOn = !powerisOn;
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
    qInfo("displaying battery");
    qInfo("battery level: %d", battery->getBatteryLevel());

//Prob find a cleaner way to do this
    for(int i = 1; i <= battery->getBatteryLevel(); i++){
        qInfo("%d", i);
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
    qInfo("Lit");
//store in a key value pair??

    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_dutyCycle_CESsession.png" : ":/res/icons/unLit/icon_dutyCycle_CESsession.png", ui->dutyCycle_CESsession);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_shortPulse_CESsession.png" : ":/res/icons/unLit/icon_shortPulse_CESsession.png", ui->shortPulse_CESsession );
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_LeftCESchannel.png" : ":/res/icons/unLit/icon_LeftCESchannel.png", ui->left_CESchannel);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_RightCESchannel.png" : ":/res/icons/unLit/icon_RightCESchannel.png",  ui->right_CESchannel);

 //session times
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_25Min.png" : ":/res/icons/unLit/session_times/icon_25Min.png", ui->session_25min);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_45Min.png" : ":/res/icons/unLit/session_times/icon_45Min.png", ui->session_45min);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_3Hour.png" : ":/res/icons/unLit/session_times/icon_3Hour.png", ui->session_3hr);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_customTime.png" :  ":/res/icons/unLit/session_times/icon_customTime.png",  ui->session_custom);

//column numbers
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_8.png" : ":/res/icons/unLit/colNumbers/icon_8.png",  ui->col_num_8);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_7.png" : ":/res/icons/unLit/colNumbers/icon_7.png",  ui->col_num_7);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_6.png" : ":/res/icons/unLit/colNumbers/icon_6.png",  ui->col_num_6);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_5.png" : ":/res/icons/unLit/colNumbers/icon_5.png",  ui->col_num_5);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_4.png" : ":/res/icons/unLit/colNumbers/icon_4.png",  ui->col_num_4);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_3.png" : ":/res/icons/unLit/colNumbers/icon_3.png",  ui->col_num_3);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_2.png" : ":/res/icons/unLit/colNumbers/icon_2.png",  ui->col_num_2);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_1.png" : ":/res/icons/unLit/colNumbers/icon_1.png",  ui->col_num_1);

//session types
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_alpha.png" : ":/res/icons/unLit/sessions/icon_alpha.png", ui->session_alpha );
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_SMR.png" : ":/res/icons/unLit/sessions/icon_SMR.png", ui->session_SMR);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_Beta.png" : ":/res/icons/unLit/sessions/icon_Beta.png", ui->session_Beta);
    changePixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_100Hz.png" : ":/res/icons/unLit/sessions/icon_100Hz.png", ui->session_100Hz);

    icon_ALL_Lit = !icon_ALL_Lit;

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

