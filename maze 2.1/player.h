#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"
#include "prop.h"
#include "keyobject.h"
//#include "room.h"
#include <vector>
using namespace std;

class room;

class player : public agent
{
    public:
        player();
        bool act () ;
        bool lose=false;
        void addPlayerProp(prop *o);
        void removePlayerProp(prop *o);
        void addPlayerKeyobject(keyobject *o);
        void removePlayerKeyobject(keyobject *o);
        bool canKillIt=false;
    protected:
        vector<keyobject*> playerKeyobject;
        vector<prop*> playerProp;
    private:
};

#endif // PLAYER_H
