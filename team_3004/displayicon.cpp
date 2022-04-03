#include "displayicon.h"

DisplayIcon::DisplayIcon(QString l, QString d, QLabel* ui)
{
    illum = dim;
    iconMap.insert(lit, l);
    iconMap.insert(dim, d);
    uiElement = ui;
}
