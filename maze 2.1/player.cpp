#include "player.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
player::player()
{
    //ctor
}

bool player :: act ()
{

    while (true)
    {
        if(this->playerLost==true)
        {
            break;
        }

        cout<< endl <<"Player (" << name << ") in : "<< cur_room->getName() << ", which contains: " << cur_room->getDescription() << endl ;

        cur_room->addAgent(this) ;

        for(int i=0; i<5; i++)
        {
            if(cur_room->keyobjectArr[i]!=NULL)
            {
                this->addPlayerKeyobject(cur_room->keyobjectArr[i]);
                cur_room->removeKeyobjectFromRoom(cur_room->keyobjectArr[i]);
            }
        }
        for(int i=0; i<5; i++)
        {
            if(cur_room->propArr[i]!=NULL)
            {
                this->addPlayerProp(cur_room->propArr[i]);
                cur_room->removePropFromRoom(cur_room->propArr[i]);
            }
        }
        cur_room->printLinked() ;

        cout<<endl<<"which direction or 'quit'? " ;

        string choice ;
        cin>>choice ;
        if(choice=="quit")
            return false;

        if (choice == "north")
            if (cur_room->get_n() != NULL)
            {
                cur_room->removeAgent(this) ;
                cur_room = cur_room->get_n() ;
                if (!cur_room->printAgents())
                    cout << "no Creatures " << endl ;
                cur_room->addAgent(this) ;
                cout<<name<<" is in "<<cur_room->getName()<<endl;
            }
            else
            {
                cout<<"There is no "<<choice<<endl ;
            }

        if (choice == "west")
            if (cur_room->get_w() != NULL)
            {
                cur_room->removeAgent(this) ;

                cur_room = cur_room->get_w() ;

                if (!cur_room->printAgents())
                    cout << "no Creatures " << endl ;
                //
                cout<<name<<" is in "<<cur_room->getName()<<endl;
                cur_room->addAgent(this) ;
            }
            else
            {
                cout<<"There is no "<<choice<<endl ;
            }

        if (choice == "east")
            if (cur_room->get_e() != NULL)
            {
                cur_room->removeAgent(this) ;

                cur_room = cur_room->get_e() ;
                if (!cur_room->printAgents())
                    cout << "no Creatures " << endl ;
                //
                cout<<name<<" is in "<<cur_room->getName()<<endl;
                cur_room->addAgent(this) ;
            }
            else
            {
                cout<<"There is no "<<choice<<endl ;
            }
        if (choice == "south")
            if (cur_room->get_s() != NULL)
            {
                cur_room->removeAgent(this) ;

                cur_room = cur_room->get_s() ;
                if (!cur_room->printAgents())
                    cout << "no Creatures " << endl ;
                //
                cout<<name<<" is in "<<cur_room->getName()<<endl;
                cur_room->addAgent(this) ;
            }
            else
            {
                cout<<"There is no "<<choice<<endl ;
            }

        if(cur_room->treasureHere==true)
        {
            if(this->playerKeyobject.size()>0)
            {
                for(int i=0; i<this->playerKeyobject.size(); i++)
                {
                    if(cur_room->treasureName==this->playerKeyobject[i]->getObjectName())
                    {
                        cout<<"Game over player "<<this->getName()<<" found the treasure !!"<<endl;
                        return false ;
                    }
                }
            }
            else
            {
                cout<<"player: "<<this->getName()<<"don't have key"<<endl;
            }
        }
        if(cur_room->monsHere==true)
        {
            if(this->playerProp.size()>0)
            {
                for(int i=0; i<this->playerProp.size(); i++)
                {
                    if(cur_room->monsName==this->playerProp[i]->getObjectName())
                    {
                        system("PAUSE");
                        cout<<"player: "<<this->getName()<<" killed monster: "<<cur_room->monsName<<endl;
                        return false ;
                    }
                    else
                    {
                        cout<<"monster: "<<cur_room->monsName<<" killed player: "<<this->getName()<<endl;
                        this->playerLost=true;
                    }
                }
            }
            else
            {
                cout<<"monster: "<<cur_room->monsName<<" killed player: "<<this->getName()<<endl;
                this->playerLost=true;
            }
        }
        return true;

    }
}

void player :: addPlayerProp(prop *o)
{
    playerProp.push_back(o) ;
}
void player::addPlayerKeyobject(keyobject *o)
{

    playerKeyobject.push_back(o) ;


}


void player :: removePlayerProp(prop *o)
{
    for (vector<prop*>::iterator i = playerProp.begin() ; i!=playerProp.end() ; i++)
        if ((*i)->getObjectName() == o->getObjectName())
        {
            playerProp.erase(i);
        }
}
void player::removePlayerKeyobject(keyobject *o)
{
    for (vector<keyobject*>::iterator i = playerKeyobject.begin() ; i!=playerKeyobject.end() ; i++)
        if ((*i)->getObjectName() == o->getObjectName())
        {
            playerKeyobject.erase(i);
        }
}
