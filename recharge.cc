#include "recharge.h"
#include "card.h"
#include "player.h"

using namespace std;

Recharge::Recharge(Player *owner):Spell{"Recharge","Spell","Your ritual gains 3 charges",1,owner}{}

Recharge::~Recharge(){}

void Recharge::activate(shared_ptr<Card> c){}

void Recharge::activate() {
    if (owner->getRitual()){
    int cur=owner->getRitual()->getRitualCharge();
    owner->getRitual()->setRitualCharge(cur+3);
   }
}
