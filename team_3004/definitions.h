/*
 * This class includes definitions and enumerations used globally throughout this program
 * */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_HZ 500
#define MAX_DURATION 1500
#define MAX_INTENSITY 8
#define MIN_INTENSITY 1

#define MAX_BATTERY 100
#define MIN_BATTERY 0

/*
 * The definitions below define how often the timers call their respective functions
 * For instance, SYSCYCLE_INTERVAL with a value of 1000 means that the SYSCYLE timer will execute its functions every 1 second
 */
#define SYSCYCLE_INTERVAL 1000
#define DISPLAY_BATTERY_INTERVAL 15 * 1000
#define SESSION_INTERVAL 1000


/*
 * The MAX_DRAIN and MIN_DRAIN defintions are used in device to compute the amount of battery to drain every hour.
 * The amount to comupte is a function of session intensity.
 * Note that the assumtions on the hours are from the top of page 4 of the manual.
 * To compute the max, assume 25 hours for an intensity of 8. This leads to a drain of 4% every hour, for a maxed intensity.
 * To compute the min, assume 30 hours for min intensity. This equates to a drain of 3.33 every hour.
 */
#define MAX_DRAIN 4
#define MIN_DRAIN 3.33

#define CONNECTION_SIM okay


enum CEStype {pulse, cycle};
enum ConnectionState {none, okay, excellent};
enum PowerState {on, off};

/*
 * The UseCase enum is our solution to the overloaded assignment to buttons
 * IE this solves the following issue: How  can we make it so that, for example, the power button only turns on the device when it's off, while making it so that it cycles the session length when selecting session?
 * More documentation on this is provided in device.cpp
 */
enum UseCase {blank, selectingSession, runningSession, loadingConnection, lowBattery, deadBattery, loadingSession, endingSession, displayingBattery, softOn, pausedSession};
enum IllumState {lit, dim, flashing};

#endif // DEFINITIONS_H
