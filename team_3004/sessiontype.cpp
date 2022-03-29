using namespace std;
#include "sessiontype.h"
#include <stdexcept>

SessionType::SessionType(float minHzPass, float maxHzPass, CEStype csModePass )
{

    if (minHzPass < 0 || minHzPass >= maxHzPass) {
        throw std::invalid_argument("minimum hz invalid");
        minHz = 1;
    }
    else {
        minHz = minHzPass;
    }

    if (maxHzPass < 0 || maxHzPass > MAX_HZ) {
        throw std::invalid_argument("maximum hz invalid");
        maxHz = 500;

    }
    else {
        maxHz = maxHzPass;

    }
    csMode = csModePass;




}
