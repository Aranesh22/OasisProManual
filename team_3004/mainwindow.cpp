#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    show_battery();
//    qInfo("%d", battery->getBattery_percent());

}


//cahnges power display button between it's on and off state
void MainWindow::show_power(){
    qInfo("changing power display ");
    QIcon x = QIcon(powerisOn ? ":/res/buttons/powerBtn_lit.png" : ":/res/buttons/power_Btn_unLit.png");
//    QIcon x = QIcon(powerisOn ? ":/res/buttons/power_Btn_unLit.png" : ":/res/buttons/powerBtn_lit.png");
    ui->pushButton_8->setIcon(x);
    lit();
    powerisOn = !powerisOn;
}

void MainWindow::show_battery(){
    qInfo("displaying battery");
    qInfo("battery level: %d", battery->getBatteryLevel());

//Prob find a cleaner way to do this
    for(int i = 1; i <= battery->getBatteryLevel(); i++){
        qInfo("%d", i);
        if(i == 1){
            QPixmap icon_col_num_1 = QPixmap(":/res/icons/Lit/colNumber/icon_1.png");
            ui->col_num_1->setPixmap(icon_col_num_1);
        }

        if(i == 2){
            QPixmap icon_col_num_2 = QPixmap(":/res/icons/Lit/colNumber/icon_2.png");
            ui->col_num_2->setPixmap(icon_col_num_2);
        }

        if(i == 3){
            QPixmap icon_col_num_3 = QPixmap(":/res/icons/Lit/colNumber/icon_3.png");
            ui->col_num_3->setPixmap(icon_col_num_3);
        }
        if(i == 4){
            QPixmap icon_col_num_4 = QPixmap(":/res/icons/Lit/colNumber/icon_4.png");
            ui->col_num_4->setPixmap(icon_col_num_4);
        }
        if(i == 5){
            QPixmap icon_col_num_5 = QPixmap(":/res/icons/Lit/colNumber/icon_5.png");
            ui->col_num_5->setPixmap(icon_col_num_5);
        }
        if(i == 6){
            QPixmap icon_col_num_6 = QPixmap(":/res/icons/Lit/colNumber/icon_6.png");
            ui->col_num_6->setPixmap(icon_col_num_6);
        }
        if(i == 7){
            QPixmap icon_col_num_7 = QPixmap(":/res/icons/Lit/colNumber/icon_7.png");
            ui->col_num_7->setPixmap(icon_col_num_7);
        }
        if(i == 8){
            QPixmap icon_col_num_8 = QPixmap(":/res/icons/Lit/colNumber/icon_8.png");
            ui->col_num_8->setPixmap(icon_col_num_8);
        }

    }

}




// lights up all the icons to their powered on state
//Might need flags to show if an icon is lit or not
void MainWindow::lit(){
    qInfo("Lit");
    QPixmap icon_dutyCycle_CESsession  = QPixmap(dutyCycle_CESsession_icon_lit ? ":/res/icons/Lit/icon_dutyCycle_CESsession.png" : ":/res/icons/unLit/icon_dutyCycle_CESsession.png");
    ui->dutyCycle_CESsession->setPixmap(icon_dutyCycle_CESsession);

    QPixmap icon_shortPulse_CESsession = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_shortPulse_CESsession.png" : ":/res/icons/unLit/icon_shortPulse_CESsession.png");
    ui->shortPulse_CESsession->setPixmap(icon_shortPulse_CESsession);

    QPixmap icon_LeftCESchannel = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_LeftCESchannel.png" : ":/res/icons/unLit/icon_LeftCESchannel.png");
    ui->left_CESchannel->setPixmap(icon_LeftCESchannel);

    QPixmap icon_RightCESchannel = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/icon_RightCESchannel.png" : ":/res/icons/unLit/icon_RightCESchannel.png");
    ui->right_CESchannel->setPixmap(icon_RightCESchannel);



    QPixmap icon_25Min = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_25Min.png" : ":/res/icons/unLit/session_times/icon_25Min.png");
    ui->session_25min->setPixmap(icon_25Min);

    QPixmap icon_45Min = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_45Min.png" : ":/res/icons/unLit/session_times/icon_45Min.png");
    ui->session_45min->setPixmap(icon_45Min);

    QPixmap icon_3hr = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_3Hour.png" : ":/res/icons/unLit/session_times/icon_3Hour.png");
    ui->session_3hr->setPixmap(icon_3hr);

    QPixmap icon_customTime = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessionTimes/icon_customTime.png" :  ":/res/icons/unLit/session_times/icon_customTime.png");
    ui->session_custom->setPixmap(icon_customTime);




    QPixmap icon_col_num_8 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_8.png" : ":/res/icons/unLit/colNumbers/icon_8.png");
    ui->col_num_8->setPixmap(icon_col_num_8);

    QPixmap icon_col_num_7 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_7.png" : ":/res/icons/unLit/colNumbers/icon_7.png");
    ui->col_num_7->setPixmap(icon_col_num_7);

    QPixmap icon_col_num_6 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_6.png" : ":/res/icons/unLit/colNumbers/icon_6.png");
    ui->col_num_6->setPixmap(icon_col_num_6);

    QPixmap icon_col_num_5 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_5.png" : ":/res/icons/unLit/colNumbers/icon_5.png");
    ui->col_num_5->setPixmap(icon_col_num_5);

    QPixmap icon_col_num_4 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_4.png" : ":/res/icons/unLit/colNumbers/icon_4.png");
    ui->col_num_4->setPixmap(icon_col_num_4);

    QPixmap icon_col_num_3 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_3.png" : ":/res/icons/unLit/colNumbers/icon_3.png");
    ui->col_num_3->setPixmap(icon_col_num_3);

    QPixmap icon_col_num_2 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_2.png" : ":/res/icons/unLit/colNumbers/icon_2.png");
    ui->col_num_2->setPixmap(icon_col_num_2);

    QPixmap icon_col_num_1 = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/colNumber/icon_1.png" : ":/res/icons/unLit/colNumbers/icon_1.png");
    ui->col_num_1->setPixmap(icon_col_num_1);


    QPixmap icon_session_alpha  = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_alpha.png" : ":/res/icons/unLit/sessions/icon_alpha.png");
    ui->session_alpha->setPixmap(icon_session_alpha);

    QPixmap icon_session_SMR  = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_SMR.png" : ":/res/icons/unLit/sessions/icon_SMR.png");
    ui->session_SMR->setPixmap(icon_session_SMR);

    QPixmap icon_session_Beta = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_Beta.png" : ":/res/icons/unLit/sessions/icon_Beta.png");
    ui->session_Beta ->setPixmap(icon_session_Beta);

    QPixmap icon_session_100Hz  = QPixmap(icon_ALL_Lit ? ":/res/icons/Lit/sessions/icon_100Hz.png" : ":/res/icons/unLit/sessions/icon_100Hz.png");
    ui->session_100Hz->setPixmap(icon_session_100Hz);


    dutyCycle_CESsession_icon_lit = !dutyCycle_CESsession_icon_lit;
    icon_ALL_Lit = !icon_ALL_Lit;

}



void MainWindow::unLit(){

}



MainWindow::~MainWindow()
{
    delete ui;
}

