#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

#include "displayicon.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    device = new Device(ui);

    connect(ui->pushButton_Power, &QPushButton::pressed, this, &MainWindow::show_power);
    connect(ui->pushButton_Up, &QPushButton::pressed, this, &MainWindow::moveNext);
    connect(ui->pushButton_Down, &QPushButton::pressed, this, &MainWindow::moveBack);
    connect(ui->pushButton_Select, &QPushButton::pressed, this, &MainWindow::makeSelection);
    connect(ui->pushButton_Save, &QPushButton::pressed, this, &MainWindow::makeSave);

    connect(ui->pushButton_Disconnect, &QPushButton::pressed, this, &MainWindow::handleDisconnection);
    connect(ui->pushButton_BatteryDeath, &QPushButton::pressed, this, &MainWindow::handleDeadBattery);
    connect(ui->pushButton_Charge, &QPushButton::pressed, this, &MainWindow::handleCharge);

}

void MainWindow::makeSave() {
    if (device->curSession == nullptr || device ->curSession = NULL) {
        //This is where loading a recorded session will take place
        //First we must get all the recorded sessions and display them to the user



    }

    qInfo()<< "Main Window Save";
    vector<QString> toAdd = device->uploadSaveSession();
    if(toAdd.size() == 0) return;


    QTableWidget* t = ui->tableWidget;

    QTableWidgetItem* item_1 = new QTableWidgetItem;
    item_1->setIcon(QIcon(toAdd.at(1)));


    QLabel* lbl_item_1 = new QLabel();
    lbl_item_1->setPixmap(QPixmap(toAdd.at(1)));
    lbl_item_1->setAlignment(Qt::AlignCenter);

    QTableWidgetItem* item_2 = new QTableWidgetItem;
    item_2->setIcon(QIcon(toAdd.at(2)));

    QLabel* lbl_item_2 = new QLabel();
    lbl_item_2->setPixmap(QPixmap(toAdd.at(2)));
    lbl_item_2->setAlignment(Qt::AlignCenter);

    QTableWidgetItem* item_3 = new QTableWidgetItem;
    item_3->setText(toAdd.at(0));
    item_3->setTextAlignment(Qt::AlignCenter);
    item_3->setForeground(QBrush(QColor(0,255,0)));
    //text white


    t->insertRow( t->rowCount() );
    t->setCellWidget(t->rowCount()-2,1,lbl_item_1);
    t->setCellWidget(t->rowCount()-2,0,lbl_item_2);
    t->setItem(t->rowCount()-2,2,item_3);
    //tableWidget->insertRow( tableWidget->rowCount() );


    update();
}

void MainWindow::show_power(){
    device->handlePowerButton();
    update();
}


void MainWindow::moveNext(){
   device->handleUpArrow();
   update();
}



void MainWindow::moveBack(){
    device->handleDownArrow();
    update();
}

void MainWindow::makeSelection() {

    device->handleCheck();

    update();
}


void MainWindow::handleDisconnection(){
    qInfo() << "MainWindow::handleDisconnection()";

}

void MainWindow::handleDeadBattery(){
    qInfo() << "MainWindow::handleDeadBattery()";

}



void MainWindow::handleCharge(){
    device->chargeBattery();
}


//UNUSED FUNCTIONS __________________________________________________________________________________


void MainWindow::update(){
//get all icons
//    qInfo() << "MainWindow::update()";

    icons = device->getIcons();

//    for(int i = 0; i < icons.size(); i++){
//        swapIcon(icons[i]->getPath() , icons[i]->getUiElement());
//    }
}





//changes icon
void MainWindow::swapIcon(QString iconPath, QPushButton* uiIcon){
//    QIcon newIcon = QIcon(iconPath);
//    uiIcon->setIcon(newIcon);
}


//Found on stack overflow - look more into this function and prob modify it
//https://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
void MainWindow::delayBy(int n)
{
//    QTime dieTime= QTime::currentTime().addSecs(n);
//    while (QTime::currentTime() < dieTime)
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

//        QEventLoop loop;
//        QTimer t;
//        t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
//        t.start(n);
//        loop.exec();

}



MainWindow::~MainWindow()
{
    delete ui;
}
