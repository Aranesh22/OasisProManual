#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>
#include "battery.h"
#include "device.h"

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

    bool icon_ALL_Lit;
    Device* device;
    Battery* battery;

private slots:

    void show_power();
    void moveNext();
    void moveBack();
    void makeSelection();


private:
    Ui::MainWindow *ui;

    bool powerisOn;
};
#endif // MAINWINDOW_H
