#include "fireelem.h"
#include <iostream>
using namespace std;

FireElem:: FireElem(Player *owner):
  Minion{"Fire Elemental","Minion","Whenever an opponent's minion enters play, deal 1 damage to it",2,owner,2,2,0}{}

FireElem::~FireElem(){}

void FireElem::activate(){}

void FireElem::activate(shared_ptr<Card> target){}

void FireElem::notify(const string event){
    if (event=="enter"&& !isSilence && owner != owner->getBoard()->getActive()) {
        owner->getBoard()->getActive()->getMinion().back()->beAttacked(1);
    }
}
