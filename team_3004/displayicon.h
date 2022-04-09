#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QTimer>
#include <QMovie>





class DisplayIcon : public QObject
{
    Q_OBJECT
public:
    DisplayIcon(QString, QString, QPushButton*);
    DisplayIcon(QString, QString, QString, QPushButton*);
    //getters
    QString getPath();
    QPushButton* getUiElement();

    void setIllumState(IllumState);
    void toggleIllum();
    void flash();
    void swapIcon();




private:
    IllumState illum;
    QString iconMap[3];
    QPushButton* uiElement;
    QMovie* movie;
    bool hasFlash();
};

#endif // DISPLAYICON_H
