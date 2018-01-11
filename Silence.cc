#include "Silence.h"
#include <iostream>
using namespace std;

Silence::Silence(Player *owner): Enchantment{ "Silence", "Enchantment", "Enchanted minion cannot use abilities", 1, owner, 0, 0 } {}

Silence::~Silence() {}

void Silence::activate(shared_ptr<Card> c) {
  cout<<"using silence"<<endl;
  c->silence();
}

void Silence::deactivate(shared_ptr<Card> c) {
}
