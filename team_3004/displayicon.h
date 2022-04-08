#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"

#include <QPushButton>

class DisplayIcon
{
public:
    DisplayIcon(QString, QString, QPushButton*);

    //getters
    QString getPath();
    QString getPathAt(IllumState);
    QPushButton* getUiElement();

    void setIllumState(IllumState);
    void toggleIllum();

private:
    IllumState illum;
    QString iconMap[2];
    QPushButton* uiElement;

};

#endif // DISPLAYICON_H
