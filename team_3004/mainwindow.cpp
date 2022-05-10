#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <definitions.h>
#include <QTime>

#include "displayicon.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QComboBox>


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
    connect(ui->pushButton_Connect, &QPushButton::pressed, this, &MainWindow::handleConnect);
    connect(ui->pushButton_BatteryDeath, &QPushButton::pressed, this, &MainWindow::handleDeadBattery);
    connect(ui->pushButton_Charge, &QPushButton::pressed, this, &MainWindow::handleCharge);
    connect(ui->pushButton_FullCharge, &QPushButton::pressed, this, &MainWindow::handleFullCharge);

}

void MainWindow::makeSave() {
    device->handleSave();
}

void MainWindow::show_power(){
    device->handlePowerButton();
}


void MainWindow::moveNext(){
   device->handleUpArrow();
}


void MainWindow::moveBack(){
    device->handleDownArrow();
}

void MainWindow::makeSelection() {
    device->handleCheck();
}


void MainWindow::handleDisconnection(){
    device->simDisconnection();
}

void MainWindow::handleDeadBattery(){
    float drainBy = (device->getBattery()->getBatteryPercent() >= 15) ? device->getBattery()->getBatteryPercent() - 15 : 0 ;
    device->getBattery()->drain(drainBy);
    ui->battery_progressBar->setValue(device->getBattery()->getBatteryPercent());
}

void MainWindow::handleFullCharge(){
    ui->chargeBy->setValue(99);
    device->chargeBattery();
}

void MainWindow::handleCharge(){
    device->chargeBattery();
}

void MainWindow::handleConnect(){
    device->simReconnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}
