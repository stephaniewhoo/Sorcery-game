#include "player.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include "card.h"
#include "minion.h"
#include "enchantment.h"
#include "ritual.h"
#include "spell.h"
#include "ascii_graphics.h"

using namespace std;

Player:: Player() : deck{nullptr},board{nullptr}
{
}

void Player:: setMaxMagic(int i) {
  maxMagic = i;
}

void Player:: setName(string name) {
  this->name = name;
}

string Player:: getName()
{return name;}

Player:: ~Player(){
}

void Player::addHealth(int i) {
  health += i;
} 

void Player::addMaxMagic(int i) {
  maxMagic += i;
}

void Player::addMagic(int i) {
  magic += i;
} 

void Player::subMagic(int i) {
  magic -=i;
}   // if already 0?

Board * Player::getBoard(){
  return board;
}

void Player::setBoard(Board *b) {
  board = b;
}

void Player::draw(){ // to see if hand is full
  if (!isHandFull()){
    if (deck->decksize() == 0) {
      cout << "Your deck has no cards left" << endl;
    } else {
      hand.emplace_back(deck->popDeck()); //draw a card from deck(top) to hand
    }
  } else {
    cout << "your hand is too full" << endl;
  }   
}

void Player::play(int i) {
  if (i < hand.size()){
    int charge = hand.at(i)->getCost();
    if (magic >= charge) { // check if enough magic 
      magic -= charge;
      string type = hand.at(i)->getType();
      if (type == "Minion") {
        minion.emplace_back(hand.at(i));
        board->changeState("enter");
      } else if (type == "Ritual") {
	r = hand.at(i);
      } else{  // spell with no target 
        hand.at(i)->activate();
      }
      hand.erase(hand.begin()+i);
    }
    else {
      cout << "Sorry! You do not have enough magic value!" << endl;
    }
  } else {
    cout << "Invalid hand card index!" << endl;
  }
}

void Player::play(int i, shared_ptr<Card> target) { // in board, transform t to a card ptr
  if (i<hand.size()){
    int charge = hand[i]->getCost(); 
    if (magic >= charge) {
      magic -= charge;  
      string type=hand.at(i)->getType();
      cout << type << endl;
      if (type == "Enchantment") {
	target->addEnchant(hand[i]); //minion->add(Enchant);
      } else {
	hand.at(i)->activate(target); // spell with a target
      }
      hand.erase(hand.begin()+i);
    } else {
      cout << "Sorry! You do not have enough Magic Value! " << endl;  
    }
  } else {
    cout << "Invalid hand card index" << endl;
  }
}

vector<std::shared_ptr<Card>> &Player::getGraveyard(){
  return graveyard;
}


vector<std::shared_ptr<Card>> &Player::getMinion(){
  return minion;
}

bool Player:: isHandFull() {
  int num = hand.size();
  return (num==5);
}

void Player:: discard(int i){  // memory leak?
  hand.erase(hand.begin()+i); 
} 

void Player:: setdeck(const std::string filename){//setdeck input:deck.default
  deck = make_shared<Deck>(filename,this); //OK
}

void Player:: beAttacked(int i){
  health -=i; // if dead 
}

void Player:: attack(int i, Player *p) {
  minion.at(i)->attack(p);
}

void Player:: attack (int i, int j) {
  if (i < minion.size() && getBoard()->getInactive()->getMinion().size() > j ){
    minion.at(i)->attack(this->getBoard()->getInactive()->getMinion().at(j));
  }
  else {cout << "Invalid index! Please try again!" << endl;}
}

void Player:: shuffleDeck(){
  deck->shuffle(); //OK
}

std::vector<std::shared_ptr<Card>> &Player:: getHand(){
  return hand;
}

void Player::endTurn() {
    board->changeState("end");
}

void Player::startTurn() { //draw OK
  ++maxMagic;
  magic = maxMagic;
  draw();
  board->changeState("start");
  for (auto n: minion) {
    int newmax = n->getMaxActPts();
    n->setActPts(newmax);
    while (n->getActPts() < newmax) {
      n->incActPts();
    }
  }
}


bool Player::isDead() {
    return (health<=0);
}

void Player::goToGrave(std::shared_ptr<Card> card) {
  //  shared_ptr<Minion> card= static_cast<shared_ptr<Minion>>(c);
  int enchantSize = card->getEnchants().size();
  if(enchantSize > 0){
    for(int i = 0; i < enchantSize; ++i){
      card->popEnchant();
    }
  }
  for(int i = 0; i < minion.size(); ++i){
    if(minion[i] == card){
      minion.erase(minion.begin()+i);
      break;
    }
  }
  graveyard.emplace_back(card);
  board->changeState("leave");
}

int Player::getMagic() {return magic;}

void Player::returnCard(std::shared_ptr<Card> card){
  if (hand.size()<5) {
    int i =0;
    for (auto n:minion) {
      if (n==card) {
	minion.erase(minion.begin()+i);
	break;
      }
      ++i;
    }
    hand.emplace_back(card); 
    board->changeState("leave");
  } else {
    goToGrave(card);
  }
}

std::shared_ptr<Card> Player::getRitual() {return r;}

void Player::setRitual(std::shared_ptr<Card> r) {r=r;}

void Player::useActive(int i){
  if (i < minion.size()) {
    minion.at(i)->activate();}
  else { cout << "Invalid index! " << endl;
  }
}

void Player::useActive(int i, shared_ptr<Card> target){
  if (i < minion.size()){
    minion.at(i)->activate(target);} 
  else { cout << "Invalid index!" << endl;
  }
}

int Player::getHealth() {return health;}


int Player:: minionSize() {
  return minion.size();
}
