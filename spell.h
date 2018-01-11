#ifndef SPELL_H
#define SPELL_H
#include "card.h"
#include "player.h"

class Player;


class Spell: public Card {
    public:
    Spell(std::string name, std::string type, std::string des, int cost, Player *owner);
    void incActPts() override;
    int getAttack()const override;//
	void setAttack(int i)override;//
	int getDefence()const override; //
	void setDefence(int i)override;
	std::vector<std::shared_ptr<Card>> getEnchants() override;
	int getRitualCharge()const override;
	void setRitualCharge(int i)override;
	int getAbCost() override;
        int getRitualCost()override;
	void inspect() override;
	void setAbCost(int i) override;
	void attack(std::shared_ptr<Card> c)override;//
	void attack(Player *p)override;//
	void beAttacked(int i)override;//
        void popEnchant()override;
        void addEnchant(std::shared_ptr<Card> c)override;
	void notify(const std::string event) override;
        void silence() override; 
	virtual ~Spell();
        void setActPts(int i);
        int getActPts() const;
        int getMaxActPts()const  override;
        virtual void activate(std::shared_ptr<Card>)=0;
        virtual void activate()=0;
};


#endif
