#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>
#include "battery.h"
#include "device.h"
#include "button.h"
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void lit();
    void unLit();
    ~MainWindow();
    void changePixmap(QString, QLabel*);
    void show_battery();
    void delayBy(int);
    void initalizeVectors();

    int indexSessionTimeIcon;
    int indexSessionIcon;
    int indexIntensityIcon;
    Device* device;

    QVector<Button*> graphIconVector;
    QVector<Button*> sessionTimeIconVector;
    QVector<Button*> sessionIconVector;
    QVector<Button*> connectionIconVector;


   void incrementSessionTime();

    void decrementSessionTime();

private slots:

    void show_power();
    void moveNext();
    void moveBack();
    void makeSelection();


private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
