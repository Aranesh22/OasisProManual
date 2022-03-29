#include "sessionlength.h"
#include <stdexcept>


SessionLength::SessionLength(int durPass, bool isCustomPass)
{

    if (durPass > MAX_duration || durPass <= 0) {
        throw std::invalid_argument("duration invalid");

        durationMins = 1;
    }
    else {

        durationMins = durPass;

    }
    isCustom = isCustomPass;

}
