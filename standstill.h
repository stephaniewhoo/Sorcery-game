#ifndef STANDSTILL_H
#define STANDSTILL_H
#include "ritual.h"
#include "player.h"
class StandStill :public Ritual {
    public:
    StandStill(Player *owner);
    ~StandStill();
    void notify(const std::string event) override;
};

#endif
