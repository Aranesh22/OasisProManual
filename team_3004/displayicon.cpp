#include "displayicon.h"

DisplayIcon::DisplayIcon(QString litPath, QString dimPath, QPushButton* ui)
{
    iconMap[lit] = litPath;
    iconMap[dim] = dimPath;
    uiElement = ui;
    illum = dim;
}

//getters
QString DisplayIcon::getPath(){return iconMap[illum];}
QPushButton* DisplayIcon::getUiElement(){return uiElement;}

void DisplayIcon::setIllumState(IllumState newIllum)    {illum = newIllum;}
