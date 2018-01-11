#include "bonegolem.h"

using namespace std;

BoneGol:: BoneGol(Player *owner):
  Minion{"Bone Golem","Minion","Gain +1/+1 whenever a minion leaves play",2,owner,1,3,0}{}

BoneGol::~BoneGol(){}

void BoneGol::activate(){}

void BoneGol::activate(shared_ptr<Card> target){}

void BoneGol::notify(const string event){
    if (event=="leave" && !isSilence) {
        setDefence(getDefence()+1);
        setAttack(getAttack()+1);
    }
}
