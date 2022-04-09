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



    connect(ui->pushButton_Power, &QPushButton::pressed, this, &MainWindow::show_power);
    connect(ui->pushButton_Up, &QPushButton::pressed, this, &MainWindow::moveNext);
    connect(ui->pushButton_Down, &QPushButton::pressed, this, &MainWindow::moveBack);
    connect(ui->pushButton_Select, &QPushButton::pressed, this, &MainWindow::makeSelection);
    connect(ui->pushButton_Save, &QPushButton::pressed, this, &MainWindow::makeSave);

    sessionTimer = new QTimer(this);
//    sessionTimer->setSingleShot(true);
    connect(sessionTimer, &QTimer::timeout, this, &MainWindow::sessionTimeout);
//    sessionTimer->start(4000);

//    flashButton();

}

void MainWindow::makeSave() {
    device->uploadSaveSession();
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
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}







void MainWindow::sessionTimeout(){
    qInfo() << "sessionTimeout";

}




MainWindow::~MainWindow()
{
    delete ui;
}
