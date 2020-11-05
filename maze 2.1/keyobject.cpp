#include "keyobject.h"
#include "object.h"
#include "room.h"
#include <iostream>
using namespace std;
keyobject::keyobject():object(  "")
{

}
keyobject::keyobject(string name ):object(name)
{

}
bool keyobject :: act()
{
    return false;
}
