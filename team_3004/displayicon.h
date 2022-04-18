/*
 * This class allows us to tie QT icons and buttons to the code
 *
 * Notable data members:
 *  illum - Represents whether the element is dim, lit, or blinking. Note that this class was designed such that changing this value dynamically changes the UI
 *  iconMap - stores the png files and the gif files of the dim, lit, and blinking illumination states, respectivelt
 *  uiElement - the uiElement in mainWindow
 */



#ifndef DISPLAYICON_H
#define DISPLAYICON_H

#include "definitions.h"


#include <QPushButton>
#include <QTimer>
#include <QMovie>





class DisplayIcon : public QObject
{
    Q_OBJECT
public:
    DisplayIcon(QString, QString, QPushButton*);
    DisplayIcon(QString, QString, QString, QPushButton*);
    //getters
    QString getPath();
    void setPath(QString);
    QString getPathAt(IllumState);
    QPushButton* getUiElement();
    //setters
    void setIllumState(IllumState);
    void toggleIllum();

    void swapIcon();




private:
    IllumState illum;
    QString iconMap[3];
    QPushButton* uiElement;
    QMovie* movie;
    bool hasFlash();
    void flash();


};

#endif // DISPLAYICON_H
