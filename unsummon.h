#ifndef __UNSUMMON_H_
#define __UNSUMMON_H_
#include "spell.h"
#include "card.h"

class Unsummon: public Spell{
public:
	Unsummon(Player *owner);
	~Unsummon();
    void activate(std::shared_ptr<Card>) override;
    void activate() override;
};

#endif
