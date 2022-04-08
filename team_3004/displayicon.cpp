#include "displayicon.h"

#include <QDebug>


DisplayIcon::DisplayIcon(QString litPath, QString dimPath, QPushButton* ui)
{
    iconMap[lit] = litPath;
    iconMap[dim] = dimPath;
    uiElement = ui;
    illum = dim;
    // create a timer
      timer = new QTimer(this);

      // setup signal and slot
//      timer->setSingleShot(true);
      connect(timer, SIGNAL(timeout()),
            this, SLOT(flashs()));
    isFlashing = true;

}



//getters
QString DisplayIcon::getPath(){return iconMap[illum];}
QPushButton* DisplayIcon::getUiElement(){return uiElement;}

void DisplayIcon::setIllumState(IllumState newIllum)    {illum = newIllum;
                                                        swapIcon();}

void DisplayIcon::toggleIllum(){illum = (illum == lit) ? dim : lit; swapIcon();}


void DisplayIcon::swapIcon(){
    QIcon newIcon = QIcon(getPath());
    uiElement->setIcon(newIcon);
}


// Not done

int DisplayIcon::flashFor(int n){
    qInfo("DisplayIcon::flashFor(%d)", n);
    timer->start(1000);
        qInfo() << timer->remainingTime();
    if(n==0){
        timer->stop();
    }
    return n--;

}
void DisplayIcon::stopFlash(){
    timer->stop();
}

//
void DisplayIcon::flashs(){
    qInfo("flash");
    toggleIllum();

    qInfo() << timer->remainingTime();
    return;

//    QTimer *blink = new QTimer(this);
//    connect(blink, SIGNAL(timeout()), this, SLOT(flashButton()));
//    blink->start(1000);

}
