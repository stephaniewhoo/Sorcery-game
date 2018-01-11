#ifndef RECHARGE_H
#define RECHARGE_H
#include "spell.h"
#include "card.h"

class Recharge: public Spell{
public:
	Recharge(Player *owner);
	~Recharge();
    void activate(std::shared_ptr<Card>) override;
    void activate() override;
};

#endif
