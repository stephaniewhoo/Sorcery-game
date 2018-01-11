#include "banish.h"
#include "player.h"
#include "spell.h"
#include <iostream>

using namespace std;

Banish::Banish(Player *owner): Spell("Banish","Spell","Destroy target minion or ritual",2,owner){}

Banish::~Banish(){}

void Banish::activate(shared_ptr<Card> target){
    target->getOwner()->goToGrave(target);
    }

void Banish::activate() {}

