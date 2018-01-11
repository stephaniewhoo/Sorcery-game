#ifndef BLIZZARD_H
#define BLIZZARD_H
#include "spell.h"
#include "card.h"

class Blizzard: public Spell{
public:
	Blizzard(Player *owner);
	~Blizzard();
    void activate(std::shared_ptr<Card>) override;
    void activate() override;
};

#endif
