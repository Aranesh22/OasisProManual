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
//    w.update();
    return a.exec();
    int i = 7;

    return 0;
}
