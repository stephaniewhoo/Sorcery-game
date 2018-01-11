#include "raisedead.h"

using namespace std;

Raisedead::Raisedead(Player *owner):Spell{"Raisedead","Spell","Resurrect the top minion in your graveyarda nd set its defence to 1",1,owner}{}
Raisedead::~Raisedead(){}
void Raisedead::activate(shared_ptr<Card> target){}
void Raisedead::activate(){
    if (owner->getGraveyard().size() > 0) {
    owner->getMinion().emplace_back(owner->getGraveyard().back());
    owner->getGraveyard().pop_back();
    owner->getMinion().back()->setDefence(1);
    owner->getBoard()->changeState("enter");
    }
}
