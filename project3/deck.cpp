#include "deck.h"
#include"bluemeleeicon.h"
#include"bluecastericon.h"
#include"bluesiegeicon.h"
#include"bluesupericon.h"
#include"purplemeleeicon.h"
#include"purplecastericon.h"
#include"purplesiegeicon.h"
#include"purplesupericon.h"
#include"stormicon.h"
#include"graphicsview.h"
#include<QDebug>
#include"basebullet.h"

extern graphicsView *w;
deck::deck(int camp):camp(camp)
{
    if(camp==1){
        pos<<QPointF(540,700)<<QPointF(620,700)<<QPointF(700,700);
        on_deck<<1<<3<<5;
    }
    else{
        pos<<QPointF(620,20)<<QPointF(700,20);
        on_deck<<2<<4;
    }
}

void deck::refresh(){
    icons.clear();
    for(int i =0;i<on_deck.size();i++){
        switch(on_deck[i]){
        case 1:{
            icons<<new bluemeleeicon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 2:{
            icons<<new purplemeleeicon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 3:{
            icons<<new bluecastericon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 4:{
            icons<<new purplecastericon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 5:{
            icons<<new bluesiegeicon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 6:{
            icons<<new purplesiegeicon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 7:{
            icons<<new bluesupericon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 8:{
            icons<<new purplesupericon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
            break;
        }
        case 9:{
            icons<<new StormIcon;
            icons[i]->setPos(pos[i]);
            scene()->addItem(icons[i]);
        }
        }
    }
}

void deck::switchcard(int usage){
    int newcard = (camp?qrand()%5*2+1:qrand()%4*2+2);
    bool same =true;

    //check if newcard is same with anyone in the deck
    while(same){
        newcard = (camp?qrand()%5*2+1:qrand()%4*2+2);
        for(int i=0;i<on_deck.size();i++){
            if(newcard==on_deck[i]){
                same=true;
                break;
            }
            same=false;
         }
    }

    //when nothing the same, find the one to replace
    for(int i=0;i<on_deck.size();i++){
        if(usage == on_deck[i]){
            on_deck[i]=newcard;
            break;
        }
    }
    refresh();
}
