#include "mainwindow.h"

#include <QApplication>
#include "device.h"
#include "battery.h"

#include <stdexcept>
#include <QDebug>
#include "sessionlength.h"
#include "sessiontype.h"
#include "session.h"
#include <iostream>
#include <string>

//int divide(int a, int b){
//    if(b == 0) throw std::invalid_argument( "can not divide by 0" );
//    return a/b;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    Battery* b = new Battery();
//    divide(7,2);
//    qInfo("ASDFAS");

/*
    SessionLength* psl = new SessionLength(30,true);
    SessionType* pst = new SessionType(3,4.7,pulse);
    Session s(psl,pst);

    qInfo("Current intensity: %d",s.getCurIntensity());

*/
    return 0;
}
