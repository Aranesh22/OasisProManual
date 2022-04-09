#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"


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
    QString getPathAt(IllumState);
    QPushButton* getUiElement();
    //setters
    void setIllumState(IllumState);
    void toggleIllum();

    void swapIcon();




private:
    IllumState illum;
    QString iconMap[3];
    QPushButton* uiElement;
    QMovie* movie;
    bool hasFlash();
    void flash();


};

#endif // DISPLAYICON_H
