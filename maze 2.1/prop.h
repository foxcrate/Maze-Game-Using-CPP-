#ifndef PROP_H
#define PROP_H
#include <string>
#include "object.h"
#include "room.h"
using namespace std;

class prop : public object
{
    public:
        prop(string name );
        prop();
        bool act();
    protected:
    private:
};

#endif // PROP_H
