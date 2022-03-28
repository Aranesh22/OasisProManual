#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <unistd.h>
#include "battery.h"

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

    void show_battery();
    void delay();
    bool icon_ALL_Lit;
    bool dutyCycle_CESsession_icon_lit;
    bool shortPulse_CESsession_icon_lit;
    Battery* battery;

private slots:

    void show_power();


private:
    Ui::MainWindow *ui;

    bool powerisOn;
};
#endif // MAINWINDOW_H
