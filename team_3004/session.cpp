#include "session.h"
#include "sessionlength.h"
#include "sessiontype.h"

Session::Session(SessionLength* sl, SessionType* st, bool l, bool r)
{
    l = false;
    r = false;
    sl = new SessionLength();
    st = new SessionType();
}
