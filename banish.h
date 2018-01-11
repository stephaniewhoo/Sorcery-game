#ifndef __BANISH__
#define __BANISH__
#include "spell.h"
#include "card.h"

class Banish: public Spell{
public:
	Banish(Player *owner);
	~Banish();
        void activate(std::shared_ptr<Card> target) override;
	void activate() override;
};

#endif
