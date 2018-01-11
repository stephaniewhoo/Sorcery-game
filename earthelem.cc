#include "earthelem.h"

using namespace std;

EarthElem:: EarthElem(Player *owner):
  Minion{"Earth Elemental","Minion","",3,owner,4,4,0}{}

EarthElem::~EarthElem(){}

void EarthElem::activate(){}

void EarthElem::activate(shared_ptr<Card> target){}

void EarthElem::notify(const string event){}
