
#include "battery.h"

Battery::Battery()
{
    batteryPercent = 100;
    batteryLevel=0;
    qInfo("battery init");
}

int Battery::getBatteryPercent() { return batteryPercent; }
int Battery::getBatteryLevel()   { determineBatteryLevel();
                                   return batteryLevel; }


void Battery::determineBatteryLevel() {
    if (batteryPercent>87)
        batteryLevel=8;
    else
        batteryLevel=0;

}
