#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_HZ 500
#define MAX_DURATION 1500
#define MAX_INTENSITY 8
#define MIN_INTENSITY 1

#define SYSCYCLE_INTERVAL 5000
#define DISPLAYBATTERY_INTERVAL 5000
#define SESSION_INTERVAL 5000



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
enum UseCase {blank, selectingSession, runningSession, loadingConnection, lowBattery, deadBattery, loadingSession, endingSession, displayingBattery, softOn};
enum IllumState {lit, dim, flashing};

#endif // DEFINITIONS_H
