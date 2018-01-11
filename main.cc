#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include "player.h"
#include "textdisplay.h"
#include "board.h"
#include "card.h"
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {
  Player p1;
  Player p2;
  Board b;
  string mode; //What mode?
  string display; //what display?
  TextDisplay t;
  ifstream f;
  const string helpmsg = "Commands: help -- Display this message.\n""          "
    "end -- End the current player's turn.\n""          ""quit -- End the game.\n""          "
    "attack minion other-minion -- Orders minion to attack other-minion.\n""          "
    "attack minion -- Orders minion to attack the opponent.\n""          "
    "play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player.\n"
    "          "
    "use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player.\n"
    "          "
    "inspect minion -- View a minion's card and all enchantments on that minion.\n""          "
    "hand -- Describe all cards in your hand.\n""          "
    "board -- Describe all cards on the board.";
  bool init = false;
  b.setActPlayer(&p1);
  b.setInActPlayer(&p2);
  Player *activePlayer = b.getActive();
  Player *inactivePlayer = b.getInactive();
  p1.setdeck("default.deck");
  p2.setdeck("default.deck");
  p1.setBoard(&b);
  p2.setBoard(&b);
  p2.setMaxMagic(2);
  for (int i = 1; i < argc; ++i) {
    string temp = argv[i];
    if (temp == "-deck1") {
      ++i; 
      string temp2 = argv[i];
      p1.setdeck(temp2);
    }
    else if (temp == "-deck2") {
      ++i;
      string temp3 = argv[i];
      p2.setdeck(temp3);
    }
    else if (temp == "-init") {
      ++i;
      string temp2 = argv[i];
      f.open(temp2);
      //read command from file
      init = true;
    }
    else if (temp == "-testing") {
      mode = "t";
    }
    else if (temp == "-graphics") {
      display = "g";
    }
  }
  
  if (mode != "t") { //shuffle
    p1.shuffleDeck();
    p2.shuffleDeck();
    p2.shuffleDeck();
  }

  
  for (int i = 0; i < 5; ++i) {
    p1.draw();
  }

  for (int i = 0; i < 5; ++i) {//should be 5
    p2.draw();
  }
  
  
  string name1;
  string name2; //Player names
  if (init) {

    getline(f,name1);
    p1.setName(name1);
    getline(f,name2);
    p2.setName(name2);
  }
  else {
    cout << "Player1 please enter your name:" << endl;
    getline(cin,name1);
    p1.setName(name1);
    cout << "Player2 please enter your name:" << endl;
    getline(cin,name2);
    p2.setName(name2);
  }
  
  
  
  //game loop
  string cmd;
  string line; //the whole line
  while (true) {
    if (init) {
      getline(f,line);
      if (!f.good()) {
	init = false;
      }
    }
    if (!init) {
      getline(cin,line);
      if (!cin.good()) {
        break;
      }
    }
    stringstream ss{ line };
    ss >> cmd;

    if (cmd == "help") {
      cout << helpmsg << endl;
    }
    else if (cmd == "end") {
      activePlayer->endTurn();  
      inactivePlayer->startTurn();
      b.swapTurn();
      swap(activePlayer,inactivePlayer);
    }
    else if (cmd == "draw" && mode == "t") {
      activePlayer->draw();
    }
    else if (cmd == "discard" && mode == "t") {
      int index;
      ss >> index;
      --index;
      if (index < activePlayer->getHand().size()){
	activePlayer->discard(index);
      } else {
	cout << "Invalid hand card index! " << endl;
      }
    }
    else if (cmd == "attack") {
      int i; //active player index
      ss >> i;
      --i;
      int j; //inactive player index
      if (!(ss >> j)) {
        if (activePlayer->getMinion().size() > i){
	  activePlayer->getMinion()[i]->attack(inactivePlayer);}
	else {
	  cout << "Invalid index! Please try again!" << endl;
	} //Player::attack face
      } else {
        --j;
        activePlayer->attack(i, j);
      }  
    }
    else if (cmd == "play") {
      int i; //active player index
      ss >> i;
      int p; //which player
      --i;
      if (!(ss >> p)) {
	activePlayer->play(i); //just play it
      }
      else {
	int j; //inactive player index
	ss >> j;
	--j;
	if (p==1) {
	  if(j < p1.getMinion().size()) {
	    activePlayer->play(i,p1.getMinion().at(j));
	  }
	  else {
	    cout << "Invalid hand card index" << endl;
	  }
	}
	else {
	  if (p2.getMinion().size() > j){
	    activePlayer->play(i,p2.getMinion().at(j));
	  } else {
	    cout << "Invalid hand card index" << endl;
	  }
	}
      }
    }
    else if (cmd == "use") {
      int i; //active player index
      ss >> i;
      int p; 
      --i;
      if (!(ss >> p)) {
	activePlayer->useActive(i); //use activated ability on no target
      }
      else {
	int j; 
	ss >> j;
	--j;
	if (p==1){ 
	  if (j<p1.getMinion().size()){
	    activePlayer->useActive(i,p1.getMinion().at(j));
	  } else {
	    cout << "Invalid hand card index!" << endl;
	  }
	}
	else {
	  if (j<p1.getMinion().size()){
	    activePlayer->useActive(i,p2.getMinion().at(j));}
	  else {
	    cout << "Invalid hand card index!" << endl;
	  }
	}
      }
    }
    else if (cmd == "inspect") {
      int i;
      ss >> i;
      --i;
      if (i<activePlayer->getMinion().size()) {
	shared_ptr<Card> temp = activePlayer->getMinion().at(i);
	t.inspectMinion(temp);
      } else {
	cout << "Invalid hand card index!" << endl;   
      }
    }
    else if (cmd == "hand") {
      t.displayHand(activePlayer);
    }
    else if (cmd == "board") {
      t.displayBoard(&b);
    }
    else {
      cout << "invalid command" << endl;
    }
    
    if (p1.isDead()) {
      cout << "Game Over! Player 2 wins!!" << endl;
      break;
    }
    if (p2.isDead()) {
      cout << "Game Over! Player 1 wins!!" << endl;
      break;
    }    
  }
}
