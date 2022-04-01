#ifndef BUTTON_H
#define BUTTON_H


#include <QObject>
#include <QLabel>
#include <QString>

class Button
{
public:
    Button(QString, QString, QLabel*);
    QString activePath;
    QString inactivePath;
    QLabel* uiElement;
    bool state;
};

#endif // BUTTON_H
