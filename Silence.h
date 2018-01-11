#ifndef SILENCE_H
#define SILENCE_H
#include "enchantment.h"

class Silence :public Enchantment {
public:
	Silence(Player *owner);
	~Silence();
	void activate(std::shared_ptr<Card> c) override;
	void deactivate(std::shared_ptr<Card> c) override;
};
#endif // !SILENCE_H

