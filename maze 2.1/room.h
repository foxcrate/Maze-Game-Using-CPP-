#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include "agent.h"
#include "prop.h"
#include "keyobject.h"
#include <map>
using namespace std;

//class object;
class prop;
class keyobject;

class room
{
    protected:
    room *n, *s, *w, *e ;
    string name, description ;
    public:
        prop* propArr[5];
        keyobject* keyobjectArr[5];
        bool treasureHere;
        string treasureName;
        bool monsHere;
        string monsName;
        agent* content[5];
    room (string N, string D);
    string getName() ;
    string getDescription () ;
    prop* getRoomProp(int p);
    keyobject* getRoomKeyobject(int p);
    void link(room *r, string direction) ;
    room *getLinked(string direction) ;
    void printLinked() ;
    void set_s(room* r) ;
    room *get_s() ;
    void set_n(room *r) ;
    room *get_n() ;
    void set_w(room *r) ;
    room *get_w() ;
    void set_e(room *r) ;
    room *get_e() ;
    void addAgent(agent *a) ;
    void addPropToRoom(prop *o);
    void addKeyobjectToRoom(keyobject *o);
    void removePropFromRoom(prop *o);
    void removeKeyobjectFromRoom(keyobject *o);
    void removeAgent(agent * a) ;
    bool printAgents () ;
    bool printObjects();
    void set_treasureName(string name) ;
    map<string, room*> exits;
};


#endif
