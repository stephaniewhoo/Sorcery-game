#ifndef AURA_OF_POWER_H
#define AURA_OF_POWER_H
#include "ritual.h"
#include "player.h"

class AuraOfPower :public Ritual {
    public:
    AuraOfPower(Player *owner);
    ~AuraOfPower();
    void notify(const std::string event) override;
};

#endif
