#include "room.h"
#include <cstdlib>

room::room(string N, string D)
{
    //bool propHere=false;
    monsHere=false;
    treasureHere=false;
    treasureName="0";
    monsName="0";
    n = w = e = s = NULL ;
    name = N ;
    description = D ;
    for (int i = 0 ; i<5 ; i++)
        content[i] = NULL ;

    for (int i = 0 ; i<5 ; i++)
        keyobjectArr[i] = NULL ;
    for (int i = 0 ; i<5 ; i++)
        propArr[i] = NULL ;
}

string room::getName()
{
    return name ;
}

string room::getDescription()
{
    return description ;
}

void room::link(room *r, string direction)
{

    if (direction == "north")
    {
        n = r ;
        r->set_s(this) ;

    }
    if (direction == "west")
    {
        w = r ;
        r->set_e(this) ;
    }

    if (direction == "east")
    {
        e = r ;
        r->set_w(this) ;
    }

    if (direction == "south")
    {
        s = r ;
        r->set_n(this) ;
    }

}

/*room* room :: getLinked(string direction)
{
    if (direction == "north")
        return n;
    if (direction == "west")
        return w;
    if (direction == "east")
        return e;
    if (direction == "south")
        return s;

}*/
void room:: printLinked()
{
    if (n != NULL)
        cout<<"north-> "<<n->getName()<<endl;
    if (e != NULL)
        cout<<"east-> "<<e->getName()<<endl;
    if (w != NULL)
        cout<<"west-> "<<w->getName()<<endl;
    if (s != NULL)
        cout<<"south-> "<<s->getName()<<endl;

}

void room :: set_s(room *r)
{
    s = r ;
}
room *room :: get_s()
{
    return s ;
}

void room :: set_n(room *r)
{
    n = r ;
}
room *room :: get_n()
{
    return n ;
}
void room :: set_w(room *r)
{
    w = r ;
}
room *room :: get_w()
{
    return w ;
}
void room :: set_e(room *r)
{
    e = r ;
}
room *room :: get_e()
{
    return e ;
}

void room :: addAgent(agent *a)
{
    for (int i = 0 ; i<5 ; i++)
        if (content[i]==NULL)
        {
            content[i] = a ;
            break ;
        }
}
void room :: removeAgent(agent *a)
{
    for (int i = 0 ; i <5 ; i++)
        if (content[i]==a)
        {
            content[i] = NULL ;
            break;
        }
}
bool room :: printAgents ()
{
    bool contains = false ;
    cout<<"You see " ;
    for (int i = 0 ; i<5 ; i++)
    {
        if (content[i]!=NULL)
        {
            cout<<content[i]->getName()<<" // " ;
            contains = true ;
        }
    }
}
void room::addPropToRoom(prop *o)
{
    for (int i = 0 ; i<5 ; i++)
        if (propArr[i]==NULL)
        {
            propArr[i] = o ;
            break ;
        }
}
void room::addKeyobjectToRoom(keyobject *o)
{
    int i ;
    for ( i = 0 ; i<5 ; i++)
    {
        if (keyobjectArr[i]==NULL)
        {
            keyobjectArr[i] = o ;
            break ;
        }

    }


}
void room::removePropFromRoom(prop *o)
{
    for (int i = 0 ; i <5 ; i++)
        if (propArr[i]==o)
        {
            propArr[i] = NULL ;
            break;
        }
}
void room::removeKeyobjectFromRoom(keyobject *o)
{
    for (int i = 0 ; i <5 ; i++)
        if (keyobjectArr[i]==o)
        {
            keyobjectArr[i] = NULL ;
            break;
        }
}
prop* room::getRoomProp(int p)
{
    return propArr[p];
}
keyobject* room::getRoomKeyobject(int p)
{
    return keyobjectArr[p];
}

void room:: set_treasureName(string name)
{
    treasureName = name ;
}
room* room :: getLinked(string direction)
    {
        map<string, room*> :: iterator it;
        it = exits.find(direction);
        if(it != exits.end())
        {
            return it->second;
        }
        else
        {
            return NULL;
        }
    }
