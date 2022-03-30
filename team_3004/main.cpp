#include "mainwindow.h"

#include <QApplication>
//#include "device.h"
//#include "battery.h"

#include <stdexcept>
#include <QDebug>

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
//    Battery* b = new Battery();
//    Device d(b);

//    divide(7,2);
//    qInfo("ASDFAS");



}
