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



    HistoryManager* history = new HistoryManager();
    SessionLength* sl = new SessionLength(5,false);
    SessionType* st = nullptr;
    Session* testSession1 = new Session(sl,st);
    Session* testSession2 = new Session(sl,st);
    Session* testSession3 = new Session(sl,st);
    history->SaveSession(testSession1);
    history->SaveSession(testSession2);
    history->SaveSession(testSession3);

    std::vector<Session*> testVector = history->getSessions();
    for (Session* s : testVector) {
        qInfo("%d",s->getCurIntensity());
    }


    return 0;
}
