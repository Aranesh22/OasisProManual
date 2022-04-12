#include "historymanager.h"
#include <vector>
#include "session.h"

#include "QTableWidgetItem"
#include "QLabel"

HistoryManager::HistoryManager(QTableWidget* t)
{
    isLit = false;
    curSessionIndex = 0;

    table = t;
}

void HistoryManager::SaveSession(Session *saveSess) {
    sessions.push_back(saveSess);

    QString lengthPath = saveSess->getLength()->getIcon()->getPathAt(dim);
    QString typePath = saveSess->getType()->getIcon()->getPathAt(dim);

    QTableWidgetItem* length = new QTableWidgetItem;
    length->setIcon(QIcon(lengthPath));

    QLabel* lengthLabel = new QLabel();
    lengthLabel->setPixmap(QPixmap(lengthPath));
    lengthLabel->setAlignment(Qt::AlignCenter);

    QTableWidgetItem* type = new QTableWidgetItem;
    length->setIcon(QIcon(typePath));

    QLabel* typeLabel = new QLabel();
    typeLabel->setPixmap(QPixmap(typePath));
    typeLabel->setAlignment(Qt::AlignCenter);

    QTableWidgetItem* intensity = new QTableWidgetItem;
    intensity->setText( QString::number(saveSess->getCurIntensity() ) );
    intensity->setTextAlignment(Qt::AlignCenter);
    intensity->setForeground(QBrush(QColor(0,255,0)));

    table->insertRow( table->rowCount() );
    table->setCellWidget(table->rowCount()-2,1,lengthLabel);
    table->setCellWidget(table->rowCount()-2,0,typeLabel);
    table->setItem(table->rowCount()-2,2,intensity);

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

std::vector<Session*> HistoryManager::getSessions() {
    return sessions;
}

void HistoryManager::activate(){
    curSessionIndex = 0;
    table->selectRow(0);
}

void HistoryManager::selectRow(int i){
    table->selectRow(i);
}

void HistoryManager::nextSession(){
    table->clearSelection();
    if(curSessionIndex != sessions.size()-1 ) curSessionIndex++;
    table->selectRow(curSessionIndex);
}

void HistoryManager::prevSession(){
    table->clearSelection();
    if(curSessionIndex != 0 ) curSessionIndex--;
    table->selectRow(curSessionIndex);
}
