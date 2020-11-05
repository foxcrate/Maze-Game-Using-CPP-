#include "room.h"
#include "agent.h"
#include "grue.h"
#include "player.h"
#include "object.h"
#include "prop.h"
#include "keyobject.h"
#include <bits/stdc++.h>

using namespace std;
#include <string>


int main()
{
    srand(time(NULL));
    room a("kitchen","A glass of juice and some food");
    room b("bathroom","A shampoo and a big mirror");
    room c("Khaled's room","Khaled's bed and a nice song is playing") ;
    room d("Ahmed's room", "Ahmed's bed and his computer") ;
    room e("garden", "A tree and 2 dogs") ;
    room f("street","Many cars and people");
    room g("grocery","Vegetables and fruits");
    room m("mall","Clothes and electronics");
    room n("Nile","Water and some boats");
    room o("backyard","Some games for the kids and a big tree");
    room p("salon","Some beautiful furnitures and Nice guests");
    room q("parent's room","A big bed and expensive furnitures");
    room r("gym","Two dumbbells and a pull up bar");
    room s("roof","A big dog and some birds");
    a.link(&b,"north");
    a.link(&e,"south");
    a.link(&c,"east");
    a.link(&d,"west");
    b.link(&s,"north");
    b.link(&a,"south");
    b.link(&o,"east");
    b.link(&p,"west");
    c.link(&o,"north");
    c.link(&r,"south");
    d.link(&p,"north");
    d.link(&q,"south");
    e.link(&a,"north");
    e.link(&f,"south");
    e.link(&q,"west");
    e.link(&r,"east");
    f.link(&e,"north");
    f.link(&n,"south");
    f.link(&g,"east");
    f.link(&m,"west");
    q.link(&d,"north");
    q.link(&m,"south");
    r.link(&c,"north");
    r.link(&g,"south");
    prop bb("Grue");
    e.addPropToRoom(&bb);
    keyobject cc("treasure 1");
    c.addKeyobjectToRoom(&cc);
    a.treasureHere=true;
    a.set_treasureName(cc.getObjectName()) ;

    grue* monster1 = new grue();
    monster1->set_cur(&q);
    monster1->setName("Grue");

    player* player1 = new player();
    player1->set_cur(&r);
    player1->setName("Khaled") ;

    player* player2 = new player();
    player2->set_cur(&d) ;
    player2->setName("Ahmed") ;

    agent **agents = new agent*[3];
    agents[0] = player1;
    agents[1] = player2;
    agents[2] = monster1;
    while(true)
    {
        bool ok  ;
        for(int i = 0; i < 3; i++)
        {
            ok = agents[i]->act();
            if(!ok)
            {
                cout << "Game quits." << endl;
                return 0 ;
            }

        }

    }

    return 0;
}
