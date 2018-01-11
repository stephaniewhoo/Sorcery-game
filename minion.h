#ifndef MINION_H
#define MINION_H
#include <string>
#include <memory>
#include <vector>
#include "card.h"
#include "enchantment.h"

class Minion : public Card, public std::enable_shared_from_this<Minion> {
	int Attack, defense, originalAtk, originalDef;
	std::vector<std::shared_ptr<Card>> buffs;
protected:
        int actionpts = 1;
        int maxactpts = 1;
        int abCost;
        bool isSilence = false;
public:
	Minion(std::string name, std::string type, std::string des,int cost, Player *owner, int Attack, int defense, int abCost);
	~Minion();
	void incActPts() override;
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
	virtual void activate(std::shared_ptr<Card> target)=0; //about ability
	virtual void activate()=0;
	virtual void notify(const std::string event)=0;
	void setActPts(int i) override;
	int getActPts() const override;
        int getMaxActPts()const override;
	void silence() override;
	void setAbCost(int i) override;
 
};
#endif // !MINION_H
