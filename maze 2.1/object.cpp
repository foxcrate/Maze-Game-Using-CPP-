#include "object.h"
#include <iostream>
using namespace std;

object::object(string name)
{
    objectName=name;
}

void object::setObjectName(string n)
{
    objectName=n;
}
string object::getObjectName()
{
    return objectName;
}
