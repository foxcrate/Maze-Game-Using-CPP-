#include "grue.h"
#include<iostream>
#include <cstdlib>
#include "room.h"
grue::grue()
{
    //ctor
}

bool grue :: act ()
{
    int n = rand() % 4;
    string direction;
    switch(n) {
    case 0: direction = "north"; break;
    case 1: direction = "south"; break;
    case 2: direction = "west"; break;
    case 3: direction = "east"; break;
    }
    if(cur_room->getLinked(direction) != NULL) {
            cur_room->removeAgent(this) ;
            cur_room->monsHere=false;
            cur_room->monsName="0";
        cur_room = cur_room->getLinked(direction);
        cout<<name<<" in "<<cur_room->getName() << endl ;
            cur_room->addAgent(this) ;
            cur_room->monsHere=true;
            cur_room->monsName="Grue";
    }
    else  {cout<<name<<" in "<<cur_room->getName() << endl;
            cur_room->monsHere=true;
            cur_room->monsName="Grue";
    }

return true ;
}
