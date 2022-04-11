#include "displayicon.h"

#include <QDebug>
#include <QMovie>


DisplayIcon::DisplayIcon(QString litPath, QString dimPath, QPushButton* ui)
{
    iconMap[lit] = litPath;
    iconMap[dim] = dimPath;
    uiElement = ui;
    illum = dim;
    movie=NULL;

}

DisplayIcon::DisplayIcon(QString litPath, QString dimPath, QString flashPath, QPushButton* ui) : uiElement(ui){
    iconMap[lit] = litPath;
    iconMap[dim] = dimPath;
    iconMap[flashing] = flashPath;
    illum = dim;

    movie = new QMovie(this);
    movie->setFileName(iconMap[flashing]);
    connect(movie, &QMovie::frameChanged, [=]{
       uiElement->setIcon(movie->currentPixmap());
   });


}




//getters
QString DisplayIcon::getPath(){return iconMap[illum];}
QPushButton* DisplayIcon::getUiElement(){return uiElement;}

//setters
void DisplayIcon::setPath(QString newPath) {
    iconMap[illum] = newPath;
}

void DisplayIcon::setIllumState(IllumState newIllum)    {
//check if the icon setting to flash is able to flash
    if(illum == newIllum)
        return;
    if(illum==flashing || newIllum==flashing){
        flash();
        illum = (hasFlash()) ? newIllum : illum;
        swapIcon();
        return;
    }else{
        illum = newIllum;
        swapIcon();
    }
}

void DisplayIcon::toggleIllum(){illum = (illum == lit) ? dim : lit; swapIcon();}


void DisplayIcon::swapIcon(){
    QIcon newIcon = QIcon(getPath());
    uiElement->setIcon(newIcon);
}

bool DisplayIcon::hasFlash(){
    if(movie)
        return true;
    else
        return false;
}


void DisplayIcon::flash(){
    if(!hasFlash())
        return;

    if (illum!=flashing && movie->state() == QMovie::NotRunning)
        movie->start();

    else if(illum==flashing && movie->state() == QMovie::Running)
        movie->stop();
}

QString DisplayIcon::getPathAt(IllumState illumS){
    return iconMap[illumS];
}
