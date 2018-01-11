#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include <string>
#include <memory>
#include <vector>
#include "minion.h"
#include "card.h"

class Player;

class Enchantment : public Card {
	int atk, def;
public:
	Enchantment(std::string name, std::string type, std::string des, int cost, Player *owner, int atk, int def);
	~Enchantment();
	void notify(const std::string event) override;
	int getAttack()const override;
	void setAttack(int i) override;
	void attack(std::shared_ptr<Card> c) override;
	void attack(Player *p) override;
	void beAttacked(int i) override;
	int getDefence()const override;
	void inspect() override;
	int getRitualCharge()const override;
	void setRitualCharge(int i) override;
	void popEnchant() override;
	void setDefence(int i) override;
	void addEnchant(std::shared_ptr<Card> c) override;
	int getRitualCost() override;
	std::vector<std::shared_ptr<Card>> getEnchants() override;
	int getAbCost() override;
        void activate(std::shared_ptr<Card> target) = 0; //about ability
	void activate() override;
	virtual void deactivate(std::shared_ptr<Card> target) = 0;
        void setActPts(int i);
        int getActPts() const;
        int getMaxActPts()const override;
        void setAbCost(int i) override;
	void incActPts() override;
        void silence() override;
};

#endif // !ENCHANTMENT_H
