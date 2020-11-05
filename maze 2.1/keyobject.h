#ifndef KEYOBJECT_H
#define KEYOBJECT_H
#include <string>
#include "object.h"
#include "room.h"
using namespace std;

class keyobject: public object
{
    public:
        keyobject(string name );
        keyobject();
        bool act();

};

#endif // KEYOBJECT_H
