#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <memory>
#include "deck.h"
#include "board.h"


class Card;
class Ritual;
class Minion;
class Enchantment;
class Deck;


class Player final {
    std::string name;
    std::vector<std::shared_ptr<Card>> hand;
    std::shared_ptr<Deck> deck;
    int health=20;
    int magic=3;
    int maxMagic=3;
    Board *board; // has a board ptr 
    std::vector<std::shared_ptr<Card>> graveyard; //on board
    std::vector<std::shared_ptr<Card>> minion; //on board
    std::shared_ptr<Card> r; //ritual
    public:
    Player();
    ~Player();
    void addHealth(int i);
    void addMagic(int i);
    void subMagic(int i); 
    void addMaxMagic(int i); 
    int getMagic();
    int getHealth();
    void setBoard(Board *b);
    std::vector<std::shared_ptr<Card>> &getHand();
    void setName(std::string name);
    std::string getName();
    Board *getBoard();
    std::shared_ptr<Card> getRitual();
    std::vector<std::shared_ptr<Card>> &getGraveyard();
    std::vector<std::shared_ptr<Card>> &getMinion();
    void setdeck(const std::string filename); //setdeck input:deck.default
    void setRitual(std::shared_ptr<Card> r);
    int minionSize();
    void setMaxMagic(int i);   
    // end of setter and getter

    void shuffleDeck(); //ok
    void play(int i);  
    void play(int i, std::shared_ptr<Card> target); // with target
    void draw(); //done 
    void discard(int i);  
    void beAttacked(int i);
    bool isHandFull();
    void attack(int i, Player *p);
    void attack(int i, int j);
    void endTurn();
    void startTurn();
    bool isDead();
    void goToGrave(std::shared_ptr<Card> card);
    void returnCard(std::shared_ptr<Card> card);
    void useActive(int i);
    void useActive(int i, std::shared_ptr<Card> target);
    void inspect(int i);
};

#endif
