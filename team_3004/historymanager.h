/*
 * This class reprsents the history interface and its respective functionality
 *
 * Notable data members:
 *  table - the element that links an instance of this class to a mainwindow element
 *  sessions - a list of all saved sessions with their required data (notably: length, type, intensity)
 *
 * Notable data functions:
 *  activate() - highlights the first row
 *  clear() - removes all highligting in the table
 */


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
    Session* getCurSession();

    //ui
    void activate();
    void nextSession();
    void prevSession();
    int clear();

private:
    QTableWidget* table;
    bool isLit;
    vector<Session*> sessions;
    int curSessionIndex;

    //ui
    void selectRow(int);


};

#endif // HISTORYMANAGER_H
