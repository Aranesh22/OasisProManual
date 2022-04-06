#include "historymanager.h"

HistoryManager::HistoryManager()
{
    isLit = false;
    curSessionIndex = 0;
}

void HistoryManager::SaveSession(Session *saveSess) {

    sessions.push_back(saveSess);
}

Session* HistoryManager::loadSession(Session * toLoad) {
    for (Session* s : sessions) {
        if (toLoad == s) {
            return s;
        }
    }
    return NULL;
}

Session* HistoryManager::deleteSession(Session* toDelete) {
    int i = 0;
    for (Session* s : sessions) {
        if (toDelete == s) {
            sessions.erase(sessions.begin() + i);
            return s;
        }
        ++i;
    }
    return NULL;
}
