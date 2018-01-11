#include "massum.h"
#include "airelem.h"

using namespace std;

MasSum:: MasSum(Player *owner):
  Minion{"Master Summoner","Minion","Summon up to three 1/1 air elementals",3,owner,2,3,2}{}

MasSum::~MasSum(){}

void MasSum::activate(){
	if (actionpts > 0 && !isSilence) {
		int i = 0;
		if (owner->getMagic() >= abCost && owner->getMinion().size() < 5) {
			while (owner->getMinion().size() < 5 && i < 3) {
				owner->getMinion().push_back(make_shared<AirElem>(owner));
				owner->subMagic(abCost);
				++i;
			}
		}
		--actionpts;
	}
}

void MasSum::activate(shared_ptr<Card> target){}

void MasSum::notify(const string event){}
