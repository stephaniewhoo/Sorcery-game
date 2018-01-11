#ifndef MAGICFATI_H
#define MAGICFATI_H
#include "enchantment.h"

class MagicFati :public Enchantment {
public:
	MagicFati(Player *owner);
	~MagicFati();
	void activate(std::shared_ptr<Card> c) override;
	void deactivate(std::shared_ptr<Card> c) override;
};
#endif // !MAGICFATI_H

