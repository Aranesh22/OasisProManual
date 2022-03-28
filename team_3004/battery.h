#ifndef BATTERY_H
#define BATTERY_H

//this is a push INCLUDING the pro file
#define MAX_BATTERY 100

//Assume that there will be a seperate screen that can set the inital battery level when the device turns on
// For now, whenever the device turns on it will be set to 100% battery


class Battery
{
public:
    Battery();
    void battery_drain();


    void getBattery_level();

private:
    int battery_level;

};

#endif // BATTERY_H
