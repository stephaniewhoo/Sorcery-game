#include "airelem.h"
#include <iostream>
using namespace std;

AirElem:: AirElem(Player *owner):
  Minion{"Air Elemental","Minion","",0,owner,1,1,0}{}

AirElem::~AirElem(){}

void AirElem::activate(){}

void AirElem::activate(shared_ptr<Card> target){}

void AirElem::notify(const string event){}
