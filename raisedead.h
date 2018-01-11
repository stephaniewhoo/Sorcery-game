#ifndef RAISEDEAD_H
#define RAISEDEAD_H
#include "spell.h"
#include "card.h"

class Raisedead: public Spell{
public:
	Raisedead(Player *owner);
	~Raisedead();
    void activate(std::shared_ptr<Card>) override;
    void activate() override;
};

#endif
