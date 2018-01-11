#ifndef BONEGOL_H
#define BONEGOL_H
#include "player.h"
#include "card.h"
#include "minion.h"

class BoneGol : public Minion {
    public:
    BoneGol(Player *owner);
    ~BoneGol();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
