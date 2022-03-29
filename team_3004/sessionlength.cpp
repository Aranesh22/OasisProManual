using namespace std;
#include "sessionlength.h"
#include <stdexcept>


SessionLength::SessionLength(int durPass, bool isCustomPass)
{

    if (durPass > MAX_DURATION|| durPass <= 0) {
        throw ::invalid_argument("duration invalid");
    }


    durationMins = durPass;
    isCustom = isCustomPass;

}
