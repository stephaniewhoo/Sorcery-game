#include "ritual.h"
#include <string>
#include "player.h"
#include "card.h"
Ritual:: Ritual(std::string name, std::string type, std::string des, int cost, Player *owner,int charge, int actCost):
Card{name,type,des,cost,owner},charge{charge},actCost{actCost}{}

Ritual:: ~Ritual(){}
int Ritual::getMaxActPts() const {return 0;}
int Ritual::getAttack()const {return 0;}
void Ritual::setAttack(int i){}
int Ritual::getDefence()const {return 0;}
void Ritual::setDefence(int i){}
void Ritual::popEnchant(){}
void Ritual::addEnchant(std::shared_ptr<Card> c){}
std::vector<std::shared_ptr<Card>> Ritual::getEnchants(){}
int Ritual:: getAbCost(){return 0;}
void Ritual::attack(std::shared_ptr<Card> c){}
void Ritual::attack(Player *p){}
void Ritual::beAttacked(int i){}
void Ritual:: activate(std::shared_ptr<Card> target) {}
void Ritual:: activate() {}
void Ritual:: inspect(){}
int Ritual::getRitualCharge()const {
     return charge;
}
void Ritual::setRitualCharge(int i) {charge =i;}
int Ritual::getRitualCost(){return actCost;}
void Ritual:: setActPts(int i){}
void Ritual:: setAbCost(int i){}
void Ritual::silence(){}
int Ritual:: getActPts() const {return 0;}
void Ritual::incActPts() {}
