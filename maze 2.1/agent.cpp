#include "agent.h"

agent::agent()
{
    //ctor
}

bool agent :: act()
{

}

void agent :: setName(string n)
{
    name = n ;
}
string agent :: getName()
{
return name ;
}
void agent :: set_cur(room * r)
{
    cur_room = r ;
}
room * agent :: get_cur ()
{
    return cur_room ;
}
