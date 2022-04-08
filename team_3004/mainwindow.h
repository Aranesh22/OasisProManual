#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>

#include "device.h"
#include "button.h"
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
    void show_battery();

private slots:

    void show_power();
    void moveNext();
    void moveBack();
    void makeSelection();



    void sessionTimeout();

private:
    Ui::MainWindow *ui;

//UNUSED  __________________________________________________________________________________

    QTimer *sessionTimer;

    void makeSave();








};
#endif // MAINWINDOW_H
