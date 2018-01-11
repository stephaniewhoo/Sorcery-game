#include "enrage.h"
#include <iostream>
using namespace std;

Enrage::Enrage(Player *owner): Enchantment { "Enrage", "Enchantment", "", 2, owner, 2, 2 } {}

Enrage::~Enrage() {}

void Enrage::activate(shared_ptr<Card> c) {
  cout << "Using Enrage" << endl;
	int atk = c->getAttack();
	int def = c->getDefence();
	c->setAttack(atk * 2);
	c->setDefence(def * 2);
}

void Enrage::deactivate(shared_ptr<Card> c) {
	int atk = c->getAttack();
	int def = c->getDefence();
	c->setAttack(atk / 2);
	c->setDefence(def / 2);
}
