using namespace std;
#include "sessionlength.h"
#include <stdexcept>
#include <QDebug>


SessionLength::SessionLength(int durPass, bool isCustomPass)
{

    if (durPass > MAX_DURATION|| durPass <= 0) {
        throw ::invalid_argument("duration invalid");
    }

    durationMins = durPass;
    isCustom = isCustomPass;

}


SessionLength::SessionLength(int durPass, bool isCustomPass, DisplayIcon* dicon) : icon(dicon) {
    durationMins = durPass;
    isCustom = isCustomPass;
}

DisplayIcon* SessionLength::getIcon() {return icon;}

int SessionLength::getDurationMins() {

    return durationMins;
}

bool SessionLength::getIsCustom() {

    return  isCustom;
}
