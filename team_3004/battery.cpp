
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


void Battery::drainBattery(){}
void Battery::chargeBattery(){}

//decremented by 12
void Battery::determineBatteryLevel() {

// Prob find a cleaner way to code this
    if (batteryPercent>87)
        batteryLevel=8;
    else if (batteryPercent>75)
        batteryLevel=7;

    else if (batteryPercent>63)
        batteryLevel=6;

    else if (batteryPercent>51)
        batteryLevel=5;

    else if (batteryPercent>39)
        batteryLevel=4;

    else if (batteryPercent>27)
        batteryLevel=3;

    else if (batteryPercent>15)
        batteryLevel=2;

    else
        batteryLevel=1;
}
