#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QTimer>





class DisplayIcon : public QObject
{
    Q_OBJECT
public:
    DisplayIcon(QString, QString, QPushButton*);

    //getters
    QString getPath();
    QPushButton* getUiElement();
    QTimer *timer;
    void setIllumState(IllumState);
    void toggleIllum();
    int flashFor(int);
    void stopFlash();

    bool isFlashing;
    void swapIcon();
//    Ui::MainWindow ui;

public slots:
    void flashs();
private:
    IllumState illum;
    QString iconMap[2];
    QPushButton* uiElement;

};

#endif // DISPLAYICON_H
