#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>
#include <string>

class Player;
class Card;
class Ritual;

class Board { // if a pattern needed
    std::string state; // start end turn + minion leave and enter
    Player *active;
    Player *inactive;
    public:
    Board();
    ~Board();
    Player *getActive();
    Player *getInactive();
    std::string getState();
    void setActPlayer(Player *p);
    void setInActPlayer(Player *p);
    void setActRitual(std::shared_ptr<Card> r);
    void setInRitual(std::shared_ptr<Card> r);

    //void display(); // not done 
    void changeState(const std::string event); // settled string 
    void notifyObservers(const std::string event);
    void swapTurn();
};

#endif
