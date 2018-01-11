#include "enchantment.h"

using namespace std;

Enchantment::Enchantment(string name,string type, string des, int cost, Player *owner, int atk, int def): Card{name,type,des,cost,owner}, atk{atk}, def{def} {}

Enchantment::~Enchantment() {}

int Enchantment::getAttack()const {
	return atk;
}

void Enchantment::incActPts() {}

void Enchantment::setAttack(int i) {}

void Enchantment::attack(shared_ptr<Card> c) {}

void Enchantment::attack(Player *p) {};

void Enchantment::beAttacked(int i) {};

int Enchantment::getDefence()const {
	return def;
}

void Enchantment::inspect() {
//need to do
}

void Enchantment::notify(const string event) {}

int Enchantment::getRitualCharge()const { return 0; }

void Enchantment::setRitualCharge(int i) {}

void Enchantment::popEnchant() {}

void Enchantment::setDefence(int i) {}

void Enchantment::addEnchant(shared_ptr<Card> c) {}

int Enchantment::getRitualCost() { return 0; }

vector<shared_ptr<Card>> Enchantment::getEnchants() {}

int Enchantment::getAbCost() { return 0; }

void Enchantment::activate() {}

        void Enchantment::setActPts(int i){}
        int Enchantment::getActPts() const{return 0;}
        int Enchantment::getMaxActPts()const {return 0;}
        void Enchantment::setAbCost(int i) {}
        void Enchantment::silence() {}
