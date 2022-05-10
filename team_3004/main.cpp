#include "mainwindow.h"

#include <QApplication>
#include "device.h"
#include "battery.h"

#include <stdexcept>
#include <QDebug>
#include "sessionlength.h"
#include "sessiontype.h"
#include "session.h"
#include "historymanager.h"
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return 0;
}
