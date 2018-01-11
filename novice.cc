#include "novice.h"

using namespace std;


NovicePyro:: NovicePyro(Player *owner):
  Minion{"Novice Pyromancer","Minion","Deal 1 damage to target minion",1,owner,0,1,1}{}

NovicePyro::~NovicePyro(){}

void NovicePyro::activate(){}

void NovicePyro::activate(shared_ptr<Card> target){
	if (actionpts <= 0) return;
        if (!isSilence){
	--actionpts;
	target->beAttacked(1);
	owner->subMagic(1);
}
}

void NovicePyro::notify(const string event){}
