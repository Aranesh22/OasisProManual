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
    void deadBatteryUI();

private:
    Ui::MainWindow *ui;

//UNUSED  __________________________________________________________________________________

    QVector<Button*> graphIconVector;
    QVector<Button*> sessionTimeIconVector;
    QVector<Button*> sessionIconVector;
    QVector<Button*> connectionIconVector;
    QTimer *sessionTimer;
    int indexSessionTimeIcon;
    int indexSessionIcon;
    int indexIntensityIcon;

    void swapIcon(QString, QLabel*);
    void incrementUiSelection(QVector<Button*>, int&);
    void lit();
    void decrementUiSelection(QVector<Button*>, int&);
    void uniformUiChange(bool);
    void initForSelection(QVector<Button*>);
    void initalizeVectors();
    void graphDisplay(int);
    void makeSave();
    void sayHello();








};
#endif // MAINWINDOW_H
