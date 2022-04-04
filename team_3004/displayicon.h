#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"

#include <QMap>
#include <QLabel>

class DisplayIcon
{
public:
    DisplayIcon(QString, QString, QLabel*);
    DisplayIcon(QString, QString);

    //getters
    QString getPath();
    QLabel* getUiElement();

private:
    IllumState illum;
    QMap <IllumState, QString> iconMap;
    QLabel* uiElement;

};

#endif // DISPLAYICON_H
