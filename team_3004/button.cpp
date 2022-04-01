#include "button.h"
#include <QDebug>

Button::Button(QString aPath, QString iPath, QLabel* uiLabel)
{
//    qInfo() << "creating icon";
    activePath = aPath;
    inactivePath = iPath;
    uiElement = uiLabel;
    state = false;
}
