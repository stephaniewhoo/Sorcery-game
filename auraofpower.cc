#include <iostream>
#include "auraofpower.h"
using namespace std;

AuraOfPower::AuraOfPower(Player *owner):
Ritual{"Aura Of Power","Ritual","Whenever a minion enters play under your control, it gains +1/+1",1,owner,4,1}{
}

AuraOfPower::~AuraOfPower(){}

void AuraOfPower::notify(const string event){
    if (actCost <= charge){
        if (event == "enter" && owner->getBoard()->getActive() == owner){
        charge -= actCost;
        int originAttack = owner->getMinion().back()->getAttack();
        int originDefense = owner->getMinion().back()->getDefence();
        owner->getMinion().back()->setAttack(originAttack+1);
        owner->getMinion().back()->setDefence(originDefense+1);
        }
    }
    if (charge==0) {
        owner->setRitual(nullptr);
    }
}

