#include "spell.h"

Spell:: ~Spell(){}

Spell:: Spell(std::string name, std::string type, std:: string des, int cost, Player *owner): Card{name,type,des,cost,owner}{}


void Spell:: setAttack(int i){}
int Spell:: getAttack()const {return 0;}
void Spell:: attack(std::shared_ptr<Card> c){}
void Spell::attack(Player *p){}
void Spell::beAttacked(int i){}

void Spell:: incActPts() {}
int Spell::getDefence()const {return 0;}
void Spell::setDefence(int i){}
int Spell::getRitualCharge()const {return 0;}
void Spell::setRitualCharge(int i){}
void Spell::popEnchant(){}
void Spell::addEnchant(std::shared_ptr<Card> c){}
int Spell::getRitualCost(){return 0;}
std::vector<std::shared_ptr<Card>> Spell::getEnchants(){}
int Spell::getAbCost(){return 0;}
void Spell:: notify(const std::string event) {}
void Spell:: inspect() {}
void Spell:: setAbCost(int i) {}
void Spell:: setActPts(int i){}
void Spell:: silence(){}
int Spell:: getActPts() const{return 0;}
int Spell:: getMaxActPts() const {return 0;}
