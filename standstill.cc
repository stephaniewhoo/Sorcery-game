#include "standstill.h"
#include <iostream>
using namespace std;
StandStill::StandStill(Player *owner):
Ritual{"Stansdtill","Ritual","Whenever a minion enters play, desdroy it",3,owner,4,2}{}

StandStill::~StandStill(){}

void StandStill::notify(const string event){
    if (actCost <= charge){
        if(event == "enter"){
            owner->getBoard()->getActive()->getMinion().pop_back();
            charge -= actCost;
            cout << "remaining charge for stand still " << charge << endl;
        }
        if (charge==0) {
      cout << "goes in 0 ritualcharge" << endl;
            owner->setRitual(nullptr);
            }
    }
}
