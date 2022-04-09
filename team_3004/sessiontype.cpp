using namespace std;
#include "sessiontype.h"
#include <stdexcept>
#include <QDebug>


SessionType::SessionType(float minHzPass, float maxHzPass, CEStype csModePass )
{

    if (minHzPass < 0 || minHzPass >= maxHzPass) {
        throw ::invalid_argument("minimum hz invalid");
        minHz = 1;
    }

    minHz = minHzPass;

    if (maxHzPass < 0 || maxHzPass > MAX_HZ) {
        throw ::invalid_argument("maximum hz invalid");
        maxHz = 500;
    }

    maxHz = maxHzPass;
    csMode = csModePass;

}


SessionType::SessionType(float minHzPass, float maxHzPass, CEStype csModePass, DisplayIcon* dicon) : icon(dicon) {
    if (minHzPass < 0 || minHzPass >= maxHzPass) {
        throw ::invalid_argument("minimum hz invalid");
        minHz = 1;
    }

    minHz = minHzPass;

    if (maxHzPass < 0 || maxHzPass > MAX_HZ) {
        throw ::invalid_argument("maximum hz invalid");
        maxHz = 500;
    }

    maxHz = maxHzPass;
    csMode = csModePass;
}

SessionType::SessionType(float minHzPass, float maxHzPass, CEStype csModePass, DisplayIcon* dicon, DisplayIcon* cicon) : icon(dicon),  CESicon(cicon){
    if (minHzPass < 0 || minHzPass >= maxHzPass) {
        throw ::invalid_argument("minimum hz invalid");
        minHz = 1;
    }

    minHz = minHzPass;

    if (maxHzPass < 0 || maxHzPass > MAX_HZ) {
        throw ::invalid_argument("maximum hz invalid");
        maxHz = 500;
    }

    maxHz = maxHzPass;
    csMode = csModePass;
}

DisplayIcon* SessionType::getIcon() {return icon;}
DisplayIcon* SessionType::getCESIcon() {return CESicon;}

float SessionType::getMaxHz() {

    return maxHz;

}

float SessionType::getMinHz() {

    return minHz;
}

CEStype SessionType:: getCESType() {

    return csMode;
}

