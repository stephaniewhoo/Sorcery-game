#ifndef POTIONSELL_H
#define POTIONSELL_H
#include "player.h"
#include "card.h"
#include "minion.h"

class PotionSell : public Minion {
    public:
    PotionSell(Player *owner);
    ~PotionSell();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
