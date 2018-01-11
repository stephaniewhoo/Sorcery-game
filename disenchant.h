#ifndef DISENCHANT_H
#define DISENCHANT_H
#include "spell.h"
#include "card.h"

class Disenchant: public Spell{
public:
	Disenchant(Player *owner);
	~Disenchant();
    void activate(std::shared_ptr<Card>) override;
    void activate() override;
};

#endif
