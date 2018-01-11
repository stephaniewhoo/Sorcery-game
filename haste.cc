#include "haste.h"
#include <iostream>

using namespace std;

Haste::Haste(Player *owner): Enchantment{ "Haste", "Enchantment", "Enchanted minion gains +1 action each turn", 1, owner, 0, 0 } {}

Haste::~Haste(){} 

void Haste::activate(shared_ptr<Card> c) {
  int points = c->getMaxActPts() + 1;
  c->setActPts(points);
}

void Haste::deactivate(shared_ptr<Card> c) {
  int points = c->getMaxActPts() - 1;
  c->setActPts(points);
}
