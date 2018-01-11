#ifndef FIREELEM_H
#define FIREELEM_H
#include "player.h"
#include "card.h"
#include "minion.h"

class FireElem : public Minion {
    public:
    FireElem(Player *owner);
    ~FireElem();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
