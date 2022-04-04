#include "displayicon.h"

DisplayIcon::DisplayIcon(QString l, QString d, QLabel* ui)
{
    iconMap.insert(lit, l);
    iconMap.insert(dim, d);
    uiElement = ui;
    illum = dim;


}

DisplayIcon::DisplayIcon(QString l, QString d)
{
//    iconMap.insert(lit, l);
//    iconMap.insert(dim, d);
//    illum = dim;

//    uiElement = ui->pushButton_8;
}

//getters
QString DisplayIcon::getPath(){return iconMap[illum];}
QLabel* DisplayIcon::getUiElement(){return uiElement;}
