#include "GiantStre.h"
#include <iostream>
using namespace std;

GiantStre::GiantStre(Player *owner): Enchantment{ "Giant Strength", "Enchantment", "", 1, owner, 2, 2 } {}

GiantStre::~GiantStre(){}

void GiantStre::activate(shared_ptr<Card> c) {
  cout<< "activating Giant Strength" << endl;
	int points = c->getAttack() + 2;
	c->setAttack(points);
	points = c->getDefence() + 2;
	c->setDefence(points);
}
void GiantStre::deactivate(shared_ptr<Card> c) {
	cout << "deactivate Giant strength" << endl;
        int points = c->getAttack() - 2;
	c->setAttack(points);
	points = c->getDefence() - 2;
	c->setDefence(points);
}
