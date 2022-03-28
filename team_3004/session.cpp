#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"

Session::Session(SessionLength* sl, SessionType* st, int i)
{
    leftActive = false;
    rightActive = false;
    intensity = i;
    length = sl;
    type = st;
}
