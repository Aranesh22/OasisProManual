#include "historymanager.h"

HistoryManager::HistoryManager()
{
    isLit = false;
    curSessionIndex = 0;
}

void HistoryManager::SaveSession(Session *saveSess) {

    sessions.push_back(saveSess);
    curSessionIndex = curSessionIndex++;

}
