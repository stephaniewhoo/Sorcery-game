#include "unsummon.h"
#include "card.h"
#include "player.h"
#include <iostream>

using namespace std;

Unsummon::Unsummon(Player *owner):Spell{"Unsummon","Spell","Return target minion to its owner's hand",1,owner}{}

Unsummon::~Unsummon(){}


void Unsummon::activate(shared_ptr<Card> c){
     int temp = c->getEnchants().size();
	for(int i = 0; i < temp;  ++i){
		c->popEnchant();
		}
	c->getOwner()->returnCard(c);
	}

void Unsummon::activate(){}
