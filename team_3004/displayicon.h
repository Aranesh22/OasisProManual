#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"

#include <QMap>
#include <QLabel>

class DisplayIcon
{
public:
    DisplayIcon(QString, QString, QLabel*);

    //getters
    QString getPath();
    QLabel* getUiElement();

private:
    IllumState illum;
    QString iconMap[2];
    QLabel* uiElement;

};

#endif // DISPLAYICON_H
