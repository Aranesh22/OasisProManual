
#include "battery.h"

Battery::Battery()
{
    batteryLevel=0;
//    qInfo("battery init");
    initMap();
    if(!initBatteryPercent() ) batteryPercent = MAX_BATTERY;

}

int Battery::getBatteryPercent() { return batteryPercent; }

int Battery::getBatteryLevel() {
    determineBatteryLevel();
    return batteryLevel;
}

void Battery::determineBatteryLevel() { batteryLevel = batteryLevelMap.lowerBound(batteryPercent).value();}

void Battery::powerOff(){
    saveBatteryPercent();
}


bool Battery::initBatteryPercent(){
    QFile file("battery.txt");

    if(!file.exists()){
        qCritical() << "file not found";
        return false;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << file.errorString();
        return false;
    }
    QTextStream stream(&file);
    while (!stream.atEnd()){
        batteryPercent = stream.readLine().toFloat();
    }

    file.close();
    return true;
}

bool Battery::saveBatteryPercent(){
    QFile file("battery.txt"); //needs to not be in the resource tree
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "Error writing";
        qCritical() << file.errorString();
        return false;
    }
    QTextStream stream(&file);
    stream << batteryPercent;
    file.close();
    return true;
}

void Battery::initMap() {
    int level = 1;
    QFile file(":/res/battery.txt");
    if(!file.exists()){
        qCritical() << "file not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while (!stream.atEnd()){
        batteryLevelMap.insert(stream.readLine().toInt(), level);
        level++;
    }
    file.close();
}

float Battery::drain(float n){
    batteryPercent -= n;
    if(batteryPercent < 0) batteryPercent = 0;
    return batteryPercent;
}


void Battery::charge(float n){
    batteryPercent = (batteryPercent + n < MAX_BATTERY) ? batteryPercent+n : MAX_BATTERY;
}



