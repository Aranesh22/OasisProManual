#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <vector>
#include "session.h"
#include "ui_mainwindow.h"

#include <QTableWidget>


using namespace std;

class HistoryManager : public QObject
{
    Q_OBJECT
public:
    HistoryManager(QTableWidget* );
    void SaveSession(Session* );
    Session* loadSession(Session* );
    Session* deleteSession(Session* );
    vector<Session*> getSessions();

private:
    QTableWidget* table;
    bool isLit;
    vector<Session*> sessions;
    int curSessionIndex;


};

#endif // HISTORYMANAGER_H
