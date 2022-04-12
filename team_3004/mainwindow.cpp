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

void MainWindow::handleSelection() {

}

void MainWindow::cellInfo(int row, int col) {
    //Now that we have row and column we must find info from that row
    QFile file("/home/student/3004/comp3004Project/build-team_3004-Desktop-Debug/userData.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qInfo("Error opening file.");
    }

    QTextStream in(&file);

    int counter = 0;
    QString line;
    QStringList fields;
    while(!in.atEnd()) {
        line = in.readLine();
        fields = line.split(" ");

        if (counter == row) {
            break;
        }

        ++counter;
    }

    //Current session info is in fields

    QString getNumber = fields[0];
    QRegExp rx(QLatin1Literal("[^0-9]+"));
    auto&& parts = getNumber.split(rx, QString::SkipEmptyParts);
    int actualLength = parts[0].toInt();

    QString the_sl = fields[0];
    QString the_st = fields[1];
    fields[0].replace("Lit","unLit");
    fields[1].replace("Lit","unLit");


    //Set current session to new one;
    SessionLength* sl = new SessionLength(actualLength,false,new DisplayIcon(the_sl , fields[0], ui->session_alpha));

    SessionType* st = new SessionType(0.5,3,pulse,new DisplayIcon(the_st , fields[1], ui->session_alpha));

    Session* newSess = new Session(sl,st);
    device->setSession(newSess);

    update();
}

void MainWindow::moveUp() {
    if (cur_row > 0) {
        ui->tableWidget->clearSelection();
        cur_row -= 1;
        ui->tableWidget->selectRow(cur_row);
    }
}

void MainWindow::moveDown() {
    if (cur_row < lines-1) {
        ui->tableWidget->clearSelection();
        cur_row += 1;
        ui->tableWidget->selectRow(cur_row);
    }
}

void MainWindow::showRowInfo() {
    QFile file("/home/student/3004/comp3004Project/build-team_3004-Desktop-Debug/userData.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qInfo("Error opening file.");
    }

    QTextStream in(&file);

    int counter = 0;
    QString line;
    QStringList fields;
    while(!in.atEnd()) {
        line = in.readLine();
        fields = line.split(" ");

        if (counter == cur_row) {
            break;
        }

        ++counter;
    }

    device->loadSession(fields[1],fields[0],fields[2]);
    qInfo() << fields[0];
    qInfo() << fields[1];
    qInfo() << fields[2];

    //call device function
    //Pass into Session
}

void MainWindow::makeSave() {
    qInfo()<< "Main Window Save";

    if (device->getCurSession() == NULL || device->getCurSession() == nullptr) {
        cur_row = 0;
        QFile file("/home/student/3004/comp3004Project/build-team_3004-Desktop-Debug/userData.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            qInfo("Error opening file.");
        }

        //device->changeToLoadSession();
        QTextStream in(&file);
        lines = 0;
        int counter = 0;
        while(!in.atEnd()) {
            lines += 1;
            QString line = in.readLine();
            QStringList fields = line.split(" ");

            QTableWidget* table = ui->tableWidget;

            QString path_1 = fields[0];
            QString path_2 = fields[1];
            QString intensity = fields[2];

            qInfo() << path_1;

            if (counter != cur_row) {
                path_1.replace("Lit","unLit");
                path_1.replace("sessionTimes","session_times");
                path_2.replace("Lit","unLit");
            }

            QLabel* item_1 = new QLabel();
            item_1->setPixmap(QPixmap(path_1));
            item_1->setAlignment(Qt::AlignCenter);

            QLabel* item_2 = new QLabel();
            item_2->setPixmap(QPixmap(path_2));
            item_2->setAlignment(Qt::AlignCenter);

            QTableWidgetItem* item_3 = new QTableWidgetItem;
            item_3->setText(intensity);
            item_3->setTextAlignment(Qt::AlignCenter);
            item_3->setForeground(QBrush(QColor(0,255,0)));

            table->insertRow( table->rowCount() );
            table->setCellWidget(table->rowCount()-2,1,item_1);
            table->setCellWidget(table->rowCount()-2,0,item_2);
            table->setItem(table->rowCount()-2,2,item_3);
            ++counter;
        }

        file.close();

        //Here we must handle changing the current session type, length and intensity
        //connect(ui->tableWidget, &QTableWidget::pressed, this, &MainWindow::handleSelection);

        //connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(cellInfo(int,int)));


        ui->tableWidget->selectRow(cur_row);

        connect(ui->pushButton_Up, &QPushButton::pressed, this, &MainWindow::moveUp);
        connect(ui->pushButton_Down, &QPushButton::pressed, this, &MainWindow::moveDown);
        connect(ui->pushButton_Select, &QPushButton::pressed, this, &MainWindow::showRowInfo);

        //table->setItem(table->rowCount()-2,2,item_3);

        update();
        return;
    }

    QString curInt = QString::number((device->getCurSession())->getCurIntensity());
    (device->allIntensities).push_back(curInt);

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

    /*
    testing if getpath works
    vector<Session*> testVector = (device->getHistory())->getSessions();
    for (Session* s : testVector) {
        QString qs = ((s->getLength())->getIcon())->getPath();
        qInfo() << qs;
    }
    */


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
    device->simDisconnection();

}

void MainWindow::handleDeadBattery(){
    qInfo() << "MainWindow::handleDeadBattery()";

}

void MainWindow::handleFullCharge(){
    ui->chargeBy->setValue(99);
    device->chargeBattery();
//    ui->battery_progressBar->setValue(device->battery->getBatteryPercent());

}

void MainWindow::handleCharge(){
    device->chargeBattery();
}

void MainWindow::handleConnect(){
    qInfo() << "handleConnect()";
    device->simReconnect();
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
