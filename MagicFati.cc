#include "MagicFati.h"
using namespace std;

MagicFati::MagicFati(Player *owner): Enchantment{ "Magic Fatigue", "Enchantment", "Enchanted minion's activated ability costs 2 more", 0, owner, 0, 0 } {}

MagicFati::~MagicFati(){}

void MagicFati::activate(shared_ptr<Card> c){
	int cost = c->getAbCost() + 2;
	c->setAbCost(cost);
}

void MagicFati::deactivate(shared_ptr<Card> c) {
	int cost = c->getAbCost() - 2;
	c->setAbCost(cost);
}
