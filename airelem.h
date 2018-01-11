#ifndef AIRELEM_H
#define AIRELEM_H
#include "player.h"
#include "card.h"
#include "minion.h"
#include <string>

class AirElem : public Minion {
    public:
    AirElem(Player *owner);
    ~AirElem();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};




#endif

