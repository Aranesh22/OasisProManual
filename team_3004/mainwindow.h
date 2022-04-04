#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>

#include "device.h"
#include "button.h"
#include <QVector>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class Device;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void lit();
    void uniformUiChange(bool);
    void initForSelection(QVector<Button*>);
    ~MainWindow();
    void swapIcon(QString, QLabel*);
    void show_battery();
    void delayBy(int);
    void initalizeVectors();
    void graphDisplay(int);

    int indexSessionTimeIcon;
    int indexSessionIcon;
    int indexIntensityIcon;
    Device* device;

    QVector<Button*> graphIconVector;
    QVector<Button*> sessionTimeIconVector;
    QVector<Button*> sessionIconVector;
    QVector<Button*> connectionIconVector;
    void incrementUiSelection(QVector<Button*>, int&);

    QTimer *sessionTimer;

    void decrementUiSelection(QVector<Button*>, int&);


private slots:
    void deadBatteryUI();
    void show_power();
    void moveNext();
    void moveBack();
    void makeSelection();
    void sessionTimeout();


private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
