#ifndef BATTERY_H
#define BATTERY_H

//this is a push INCLUDING the pro file
#define MAX_BATTERY 100
#define MIN_BATTERY 0



#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QObject>
#include <QMap>

/*

Data Members:

    int batteryPercent : the devices battery state out of 100
    int batteryLevel : the level of battery the device has as shown on the UI
    QMap <int, int> batteryLevelMap : links the batteryPercent to the batteryLevel where the key is the batteryPercent and the value is the batteryLevel

Class Functions:

    void drainBattery() : will drain an appropriate amount of battery based on the therapy type, session length, and connection
    void chargeBattery() : will charge the battery up to MAX_BATTERY over a period of time
    void powerOff() : controls the process of shutting down the device
    void determineBatteryLevel() : determines and returns which level the current battery percentage corresponds with

    void initMap() : reads from a text file in resources that initalizes the batteryLevelMap
    void initBatteryPercent() : reads from a text file to initalize batteryPercent
    void saveBatteryPercent() : writes to a text file to save the batteryPercent variable for the devices next use

*/





class Battery
{
public:
    Battery();
    QMap <int, int> batteryLevelMap;

    float drain(float);
    void charge(float);
    void powerOff();

    int getBatteryPercent();
    int getBatteryLevel();

private:
    float batteryPercent;
    float batteryLevel;
    void determineBatteryLevel();
    void initMap();
    bool saveBatteryPercent();
    bool initBatteryPercent();


};

#endif // BATTERY_H
