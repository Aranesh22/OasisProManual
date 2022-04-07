#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_HZ 500
#define MAX_DURATION 1500
#define MAX_INTENSITY 8
#define MIN_INTENSITY 1

enum CEStype {pulse, cycle};
enum ConnectionState {connected, disconnected};
enum PowerState {on, off};
enum UseCase {blank, selectingSession, runningSession, loadingConnection, lowBattery, deadBattery, loadingSession, endingSession, displayingBattery};
enum IllumState {lit, dim};

#endif // DEFINITIONS_H
