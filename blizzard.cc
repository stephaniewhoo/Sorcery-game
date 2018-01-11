#include "blizzard.h"
#include "player.h"
#include "spell.h"
#include <iostream>
using namespace std;

Blizzard::Blizzard(Player *owner): Spell("Blizzard","Spell","Deal 2 damages to all minions",3,owner){}

Blizzard::~Blizzard(){}


void Blizzard::activate(shared_ptr<Card> target){}

void Blizzard::activate() {
   if (owner->getMinion().size() >0){
  // cout << " bigger than 0 " << endl;
   for (int i = 0; i< owner->getMinion().size(); ++i) {
   // cout << "go in active loop" << endl;
       owner->getMinion().at(i)->beAttacked(2);

   } }
   if (owner->getBoard()->getInactive()->getMinion().size() >0){
   for (int i=0; i<owner->getBoard()->getInactive()->getMinion().size(); ++i) {
//   cout << "inactive loop" << endl;
       owner->getBoard()->getInactive()->getMinion().at(i)->beAttacked(2);
   } }
 // cout << "done for blizzard" << endl;
}
