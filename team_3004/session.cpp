#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"

Session::Session(SessionLength* sl, SessionType* st, bool l, bool r, int i)
{
    l = false;
    r = false;
    intensity = i;
    sl = new SessionLength();
    st = new SessionType();
}
