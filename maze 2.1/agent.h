#ifndef AGENT_H
#define AGENT_H
#include <iostream>
using namespace std;

class room;

class agent
{
    public:
        agent();
        virtual bool act() ;
        void setName(string n) ;
        string getName() ;
        void set_cur(room * r) ;
        room * get_cur () ;
        bool playerLost=false;

    protected:
        string name;
        room * cur_room ;

};

#endif // AGENT_H
