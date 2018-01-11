#include "disenchant.h"
#include <iostream>

using namespace std;

Disenchant::Disenchant(Player *owner):Spell{"Disenchant","Spell","Destroy the top enchantment on target minion",1,owner}{}
Disenchant::~Disenchant(){}
void Disenchant::activate(shared_ptr<Card> target){
    if (target->getEnchants().size() > 0){
     cout << "disenchant after if statement" << endl;
    target->popEnchant();
     cout << "disenchant after pop" << endl;
    }
}
void Disenchant::activate(){}
