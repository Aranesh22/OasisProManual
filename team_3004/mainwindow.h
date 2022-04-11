#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>

#include "device.h"
//#include "button.h"
#include <QVector>
#include <QTimer>
#include <QPushButton>
#include "displayicon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class Device;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Device* device;
    vector<DisplayIcon*> icons;

    void swapIcon(QString, QPushButton*);
    void update();


    void delayBy(int);


private slots:

    void show_power();
    void moveNext();
    void moveBack();

    void moveUp();
    void moveDown();

    void makeSelection();

    void handleDisconnection();
    void handleDeadBattery();
    void handleCharge();
    void handleFullCharge();
    void handleConnect();

    void cellInfo(int,int);



private:
    Ui::MainWindow *ui;

//UNUSED  __________________________________________________________________________________

    void makeSave();
    void handleSelection();
    int cur_row;
    int lines;








};
#endif // MAINWINDOW_H
