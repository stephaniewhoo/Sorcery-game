#ifndef DECK_H
#define DECK_H
#include <vector>
#include <memory>
#include "player.h"

class Card;
class Player;

class Deck{
    std::vector<std::shared_ptr<Card>> content;
    Player *owner;
    public:
      Deck(const std::string filename,Player *owner);
      ~Deck();
      std::shared_ptr<Card> popDeck();
      void shuffle();
      void addCard(const std::string card);
      int decksize();
};

#endif
