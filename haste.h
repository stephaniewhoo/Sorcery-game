#ifndef HASTE_H
#define HASTE_H
#include "enchantment.h"

class Haste :public Enchantment {
public:
	Haste(Player *owner);
	~Haste();
	void activate(std::shared_ptr<Card> c) override;
	void deactivate(std::shared_ptr<Card> c) override;
};
#endif // !HASTE_H
