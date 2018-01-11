#ifndef APPRENTICE_H
#define APPRENTICE_H
#include "player.h"
#include "card.h"
#include "minion.h"

class AppSum : public Minion {
    public:
    AppSum(Player *owner);
    ~AppSum();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif

