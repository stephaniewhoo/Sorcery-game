#ifndef ENRAGE_H
#define ENRAGE_H
#include "enchantment.h"

class Enrage : public Enchantment {
public:
	Enrage(Player *owner);
	~Enrage();
	void activate(std::shared_ptr<Card> c) override;
	void deactivate(std::shared_ptr<Card> c) override;
};
#endif
