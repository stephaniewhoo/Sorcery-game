#ifndef MAGFAT_H
#define MAGFAT_H
#include "enchantment.h"

class GiantStre :public Enchantment {
public:
	GiantStre(Player *owner);
	~GiantStre();
	void activate(std::shared_ptr<Card> c) override;
	void deactivate(std::shared_ptr<Card> c) override;
};
#endif // !MAGFAT_H

