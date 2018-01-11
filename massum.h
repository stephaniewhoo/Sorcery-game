#ifndef MASSSUM_H
#define MASSUM_H
#include "player.h"
#include "card.h"
#include "minion.h"

class MasSum : public Minion {
    public:
    MasSum(Player *owner);
    ~MasSum();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
