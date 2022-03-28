#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <vector>
#include "session.h"

using namespace std;

class HistoryManager
{
public:
    HistoryManager();

private:
    bool isLit;
    vector<Session*> sessions;
    int curSessionIndex;

};

#endif // HISTORYMANAGER_H
