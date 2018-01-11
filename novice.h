#ifndef NOVICE_H
#define NOVICE_H
#include "player.h"
#include "card.h"
#include "minion.h"

class NovicePyro : public Minion {
    public:
    NovicePyro(Player *owner);
    ~NovicePyro();
    void activate() override;
    void activate(std::shared_ptr<Card>) override;
    void notify(const std::string event) override;
};


#endif
