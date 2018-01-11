#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <memory>
class Board;
class Player;
class Card;

class TextDisplay{
public:
	void displayBoard(Board *b);
	void displayHand(Player *p);
	void inspectMinion(std::shared_ptr<Card> m);
	void handFull();  
};

#endif
