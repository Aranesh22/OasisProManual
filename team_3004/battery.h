#ifndef BATTERY_H
#define BATTERY_H

//hello
//hi female dog (shady) cxZcxzc

//Assume that there will be a seperate screen that can set the inital battery level when the device turns on
// For now, whenever the device turns on it will be set to 100% battery


class Battery
{
public:
    Battery();
    battery_drain();


    getBattery_level();

private:
    int battery_level;

};

#endif // BATTERY_H
