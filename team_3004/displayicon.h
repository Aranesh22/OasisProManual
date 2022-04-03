#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"

#include <QMap>
#include <QLabel>

class DisplayIcon
{
public:
    DisplayIcon(QString, QString, QLabel*);

private:
    IllumState illum;
    QMap <IllumState, QString> iconMap;
    QLabel* uiElement;

};

#endif // DISPLAYICON_H
