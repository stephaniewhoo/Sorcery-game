#ifndef EARTHELEM_H
#define EARTHELEM_H
#include "player.h"
#include "card.h"
#include "minion.h"

class EarthElem : public Minion {
    public:
    EarthElem(Player *owner);
    ~EarthElem();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
