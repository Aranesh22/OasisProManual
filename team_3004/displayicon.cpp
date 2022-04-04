#include "displayicon.h"

DisplayIcon::DisplayIcon(QString litPath, QString dimPath, QLabel* ui)
{
    iconMap[lit] = litPath;
    iconMap[dim] = dimPath;
    uiElement = ui;
    illum = dim;
}

//getters
QString DisplayIcon::getPath(){return iconMap[illum];}
QLabel* DisplayIcon::getUiElement(){return uiElement;}
