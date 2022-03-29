using namespace std;
#include "sessiontype.h"
#include <stdexcept>

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
