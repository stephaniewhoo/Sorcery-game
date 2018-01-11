
#include "textdisplay.h"
#include "board.h"
#include "player.h"
#include "minion.h"
#include "ascii_graphics.h"
#include <iostream>
#include <memory>
#include "ritual.h"
using namespace std;





void TextDisplay::inspectMinion(shared_ptr<Card> m){
	for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); ++i){
		if(m->getType() == "Minion"){
			cout << "\033[1;33m"; //display minions in yellow
			if(m->getAbCost() != 0){
				cout << display_minion_activated_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence(),m->getAbCost(),m->getDes())[i];
			}else if(m->getDes() != ""){
				cout << display_minion_triggered_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence(),m->getDes())[i];
			}else{
				cout << display_minion_no_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence())[i];
			}
		}
		cout << endl;
	}

	vector <shared_ptr<Card>> enchantments = m->getEnchants();
	int counter = 0;
	int place = 0;
	int line = 5;
	int diff = -1;
	if(enchantments.size() <= line){
		line = enchantments.size();
	}
	for(int x = 0; x < enchantments.size(); ++x){
		if(diff == 0)
			continue;
		for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); i++){
			for(int j = counter; j < line; ++j){
				cout << "\033[0;32m"; //display rituals in blue
				if(enchantments[j]->getName() == "Enrage"){
					cout << display_enchantment_attack_defence(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDes(), "*2", "*2")[i];
				}
				else if(enchantments[j]->getName() == "Giant Strength"){
					cout << display_enchantment_attack_defence(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDes(), "+2", "+2")[i];
				}
				else{
					cout << display_enchantment(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDes())[i];
				}
				if(i == 0){
					place += 1;
				}
			}
			cout << endl;
		}
		counter += place;
		diff = enchantments.size() - line;
		if(diff < 5){
			line += diff;
		}else{
			line += 5;
		}
	}
	cout << "\033[0m";
}

void TextDisplay::displayHand(Player *p){
	int handNum = p->getHand().size();
	vector<shared_ptr<Card>> hand = p->getHand();
	for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); ++i){
		for(int j = 0; j < handNum; ++j){
			if(hand[j]->getType() == "Minion"){
				cout << "\033[1;33m"; //display minions in yellow
				if(hand[j]->getAbCost() != 0){
					cout << display_minion_activated_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence(),hand[j]->getAbCost(),hand[j]->getDes())[i];
				}else if(hand[j]->getDes() != ""){
					cout << display_minion_triggered_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence(),hand[j]->getDes())[i];
				}else{
					cout << display_minion_no_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence())[i];
				}
			}else if(hand[j]->getType() == "Ritual"){
				cout << "\033[0;31m"; //display rituals in red
				cout << display_ritual(hand[j]->getName(),hand[j]->getCost(),hand[j]->getRitualCost(),hand[j]->getDes(),hand[j]->getRitualCharge())[i];
			}else if(hand[j]->getType() == "Spell"){
				cout << "\033[0;34m"; //display Spells in blue
				cout << display_spell(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDes())[i];
			}else if(hand[j]->getType() == "Enchantment"){
				cout << "\033[0;32m"; //display enchantments in green
				if(hand[j]->getName() == "Giant Strength"){
					cout << display_enchantment_attack_defence(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDes(), "+2", "+2")[i];
				}
				else if(hand[j]->getName() == "Enrage"){
					cout << display_enchantment_attack_defence(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDes(), "*2", "*2")[i];
				}
				else{
					cout << display_enchantment(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDes())[i];
				}
			}
		}
		cout << "\033[0m" << endl; //normalization to white
	}
}


void TextDisplay::displayBoard(Board *b){
	int minionact = b->getActive()->getMinion().size();
	int minionin = b->getInactive()->getMinion().size();
	shared_ptr<Card> ritualact = b->getActive()->getRitual();
	shared_ptr<Card> ritualin = b->getInactive()->getRitual();
	bool graveyardact = false;
	bool graveyardin = false;
	if(b->getActive()->getGraveyard().size() > 0){
		graveyardact = true;
	}
	if(b->getInactive()->getGraveyard().size() > 0){
		graveyardin = true;
	}
	cout << "\033[0;36m";
	cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	for(int i = 0; i < 165; ++i){
		cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;
	// done first row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		cout << "\033[0m";
		if(ritualact != nullptr){
			cout << "\033[0;31m"; // red
			cout << display_ritual(ritualact->getName(),ritualact->getCost(),ritualact->getRitualCost(),ritualact->getDes(),ritualact->getRitualCharge())[i];
		  	cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << CARD_TEMPLATE_EMPTY[i];
		cout << "\033[0;95m";
		cout << display_player_card(1,b->getActive()->getName(),b->getActive()->getHealth(),b->getActive()->getMagic())[i];
		cout << "\033[0m";
		cout << CARD_TEMPLATE_EMPTY[i];
		if(graveyardact){
			shared_ptr<Card> dead = b->getActive()->getGraveyard().back();
			cout << "\033[0;31m"; 
			if(dead->getAbCost() != 0){
				cout << display_minion_activated_ability(dead->getName(),dead->getCost(),dead->getAttack(),dead->getDefence(),dead->getAbCost(),dead->getDes())[i];
			}else if(dead->getDes() != ""){
				cout << display_minion_triggered_ability(dead->getName(),dead->getCost(),dead->getAttack(),dead->getDefence(),dead->getDes())[i];
			}else{
				cout << display_minion_no_ability(dead->getName(),dead->getCost(),dead->getAttack(),dead->getDefence())[i];
			}  
			cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Legit Second row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		vector<shared_ptr<Card>> temp = b->getActive()->getMinion();
		cout << "\033[1;33m"; 
		for(int j = 0; j < minionact; ++j){
			if(temp[j]->getAbCost() != 0){
				cout << display_minion_activated_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence(),temp[j]->getAbCost(),temp[j]->getDes())[i];
			}else if(temp[j]->getDes() != ""){
				cout << display_minion_triggered_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence(),temp[j]->getDes())[i];
			}else{
				cout << display_minion_no_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence())[i];
			}
		}
		cout << "\033[0m";
		for(int x = 0; x < 5 - minionact; ++x){
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Center Graphic
	for(int i = 0; i < CENTRE_GRAPHIC.size(); ++i){
		cout << "\033[0;35m" << CENTRE_GRAPHIC[i] << "\033[0m" << endl;
    }
	//----END_OF----
	//Legit Second row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		vector<shared_ptr<Card>> temp = b->getInactive()->getMinion();
		cout << "\033[1;33m";
		for(int j = 0; j < minionin; ++j){
			if(temp[j]->getAbCost() != 0){
				cout << display_minion_activated_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence(),temp[j]->getAbCost(),temp[j]->getDes())[i];
			}else if(temp[j]->getDes()!=""){
				cout << display_minion_triggered_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence(),temp[j]->getDes())[i];
			}else{
				cout << display_minion_no_ability(temp[j]->getName(),temp[j]->getCost(),temp[j]->getAttack(),temp[j]->getDefence())[i];
			}
		}
		cout << "\033[0m";
		for(int x = 0; x < 5 - minionin; ++x){
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		if(ritualin != nullptr){
			cout << "\033[0;34m"; //display in blue for player 2's ritual
			cout << display_ritual(ritualin->getName(),ritualin->getCost(),ritualin->getRitualCost(),ritualin->getDes(),ritualin->getRitualCharge())[i];
		        cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << CARD_TEMPLATE_EMPTY[i];
		cout << "\033[0;95m";
		cout << display_player_card(1,b->getInactive()->getName(),b->getInactive()->getHealth(),b->getInactive()->getMagic())[i];
		cout << "\033[0m";
		cout << CARD_TEMPLATE_EMPTY[i];
		if(graveyardin){
			cout << "\033[0;31m"; //display in red for player 2's graveyard
			shared_ptr<Card> temp = b->getInactive()->getGraveyard().back();
			if(temp->getAbCost() != 0){
				cout << display_minion_activated_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getAbCost(),temp->getDes())[i];
			}else if(temp->getDes()!=""){
				cout <<display_minion_triggered_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getDes())[i];
			}else{
				cout << display_minion_no_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence())[i];
			}
			cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	cout << "\033[0;36m";
	cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for(int i = 0; i < 165; ++i){
    	cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
    cout << "\033[0m";
    //----END_OF----
}

/* void Prompt::switchMsg(Player *p1, Player *p2){
	string p1Name = p1->getName();
	string p2Name = p2->getName();
	cout << "Turn from " << p1Name << " to " << p2Name << endl;
	cout << "Active player is now " << p2Name << endl;
} */

void TextDisplay::handFull(){
	cout << "Error! Hand is Full!" << endl;
}


