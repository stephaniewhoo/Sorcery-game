#include "apprentice.h"
#include "airelem.h"
#include <iostream>
using namespace std;

AppSum:: AppSum(Player *owner):
  Minion{"Apprentice Summoner","Minion","Summon a 1/1 air elemental",1,owner,1,1,1}{}

AppSum::~AppSum(){}

void AppSum::activate(){
	if (actionpts <= 0) return;
	--actionpts;
    if (owner->getMagic() >= abCost && !isSilence && owner->getMinion().size()<5){
        owner->getMinion().push_back(make_shared<AirElem>(owner));
        owner->subMagic(abCost);
    }
}

void AppSum::activate(shared_ptr<Card> target){}

void AppSum::notify(const string event){}

