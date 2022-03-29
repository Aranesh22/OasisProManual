
#include "battery.h"

Battery::Battery()
{
    batteryPercent = 100;
    batteryLevel=0;
    qInfo("battery init");
    initMap();

}

int Battery::getBatteryPercent() { return batteryPercent; }
int Battery::getBatteryLevel()   { determineBatteryLevel();
                                   return batteryLevel; }
void Battery::determineBatteryLevel() { batteryLevel = batteryLevelMap.lowerBound(batteryPercent).value();}


void Battery::initMap() {
//decrements by 12 - prob a more efficent way to do this
    batteryLevelMap.insert(100, 8);
    batteryLevelMap.insert(87, 7);
    batteryLevelMap.insert(75, 6);
    batteryLevelMap.insert(63, 5);
    batteryLevelMap.insert(51, 4);
    batteryLevelMap.insert(39, 3);
    batteryLevelMap.insert(27, 2);
    batteryLevelMap.insert(15, 1);
}

void Battery::drainBattery(){}
void Battery::chargeBattery(){}




