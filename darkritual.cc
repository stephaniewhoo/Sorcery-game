#include "darkritual.h"
#include <iostream>
using namespace std;
DarkRitual::DarkRitual(Player *owner):
Ritual{"Dark Ritual","Ritual","At the start of your turn, gain 1 magic",0,owner,5,1}{
}

DarkRitual::~DarkRitual() {}

void DarkRitual::notify(const string event){
    if (charge >= actCost) {
      if (event == "start" && owner == owner->getBoard()->getActive()){
        owner->addMagic(1);
        charge -= actCost;
      }
    }
    if (charge==0) {
        owner->setRitual(nullptr);
    }
}
