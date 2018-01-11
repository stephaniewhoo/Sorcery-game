#include "board.h"
#include "card.h"
#include "ritual.h"
#include "minion.h"
#include "player.h"
#include <utility>
#include <iostream>
using namespace std;


Board:: Board(): state{"None"},active{nullptr},inactive{nullptr}{}

Board:: ~Board() {

}

 void Board::notifyObservers(const string event){
  if (active->minionSize() > 0) {
    for (auto n: active->getMinion()) {
        n->notify(event);
    }
}
 if (inactive->minionSize() >0) {
    for (auto n: inactive->getMinion()) {
        n->notify(event);
    }
}
    if (active->getRitual()) {
    active->getRitual()->notify(event);}
  if (inactive->getRitual()){
    inactive->getRitual()->notify(event);
  }
} 

string Board::getState() {
    return state;
}


void Board::changeState(const string event) {
    //state = event;
    notifyObservers(event);
} 

Player *Board::getActive() {
    return active;
}

Player *Board::getInactive() {
    return inactive;
}

void Board::setActPlayer(Player *p) {
    active = p;
}

void Board::setInActPlayer(Player *p) {
    inactive = p;
}

void Board::setActRitual(shared_ptr<Card> r) {
    active->setRitual(r);
}

void Board::setInRitual(shared_ptr<Card> r) {
    inactive->setRitual(r);
}

void Board::swapTurn() {
    swap(active,inactive);
}



