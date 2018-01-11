#include "minion.h"
#include <string>
#include "player.h"
#include <iostream>


using namespace std;

Minion::Minion(string name, string type, string des, int cost, Player* owner, int Attack, int defense, int abCost): Card{name,type,des,cost,owner},Attack{Attack}, defense{defense}, originalAtk{Attack}, originalDef{defense}, abCost{abCost} {}

Minion::~Minion() {}

int Minion::getAttack() const { return Attack; }

void Minion::setAttack(int i) { Attack = i; }

void Minion::attack(shared_ptr<Card> c) {
  if (actionpts > 0) {
    c->beAttacked(Attack);
    this->beAttacked(c->getAttack());
    --actionpts;
  } else {
    cout << "Not enought Action Pts" << endl;
  }
}

void Minion::attack(Player *p) {
  if (actionpts > 0) {
    p->beAttacked(Attack);
    --actionpts;
  } else {
    cout << "Not enought Action Pts" << endl;
    
  }
}

void Minion::beAttacked(int i) {
  defense -= i;
  if (defense <= 0) {
    owner->goToGrave(shared_from_this());
  }
}


int Minion::getDefence() const { return defense; }

void Minion::inspect() {}

int Minion::getRitualCharge()const {}

void Minion::setRitualCharge(int i) {}

void Minion::popEnchant() {
  int size = buffs.size() - 1;
  auto m = dynamic_pointer_cast<Enchantment>(buffs[size]);
  m -> deactivate(shared_from_this());
  buffs.pop_back();
}

void Minion::setDefence(int i) { defense = i; }

void Minion::addEnchant(shared_ptr<Card> target) {
  buffs.emplace_back(target);
  auto m = dynamic_pointer_cast<Enchantment>(target);
  m->activate(shared_from_this());
}


int Minion::getRitualCost()
{
  return 0;
}

vector<shared_ptr<Card>> Minion::getEnchants() { return buffs; }

int Minion::getAbCost() { return abCost; }

void Minion::setActPts(int i)
{
  maxactpts = i;
}

void Minion::incActPts() {
  ++actionpts;
}

int Minion::getActPts() const {
  return actionpts;
}

int Minion::getMaxActPts() const {
  return maxactpts;
}

void Minion::silence()
{
  isSilence = true;
}

void Minion::setAbCost(int i)
{
  abCost = i;
}
