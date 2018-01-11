#include "potionsell.h"

using namespace std;

PotionSell:: PotionSell(Player *owner):
  Minion{"Potion Seller","Minion","At the end of your turn, all your minions gain +0/+1",2,owner,1,3,0}{}

PotionSell::~PotionSell(){}

void PotionSell::activate(){}

void PotionSell::activate(shared_ptr<Card> target){}

void PotionSell::notify(const string event){
    if (event == "end" && !isSilence && owner== owner->getBoard()->getActive()) {
        for (auto n:owner->getMinion()){
            int cur = n->getDefence();
            n->setDefence(cur+1);
        }
    }
}
