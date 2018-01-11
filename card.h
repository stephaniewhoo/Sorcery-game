#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <memory>
#include <vector>

class Player;

class Card {
protected:
	std::string name;
	std::string type; // Minion Spell Ritual Enchantment
	std::string des;  
        int cost;
        Player* owner;
public:
	Card(std::string name, std::string type, std::string des,int cost, Player* owner);
	std::string getName()const;
	std::string getType()const;
	std::string getDes() const;
	int getCost()const;
	void setCost(int i);
        Player* getOwner()const;
	
	virtual ~Card();
	virtual void incActPts() = 0;
	virtual int getAttack()const = 0;    //m
	virtual void setAttack(int i) = 0;   //m
	virtual int getDefence()const = 0; //m
	virtual void setDefence(int i) = 0; //m
	virtual std::vector<std::shared_ptr<Card>> getEnchants() = 0;//m
	virtual int getAbCost() = 0; //m
        virtual int getRitualCharge()const = 0; //ritual pts
	virtual void setRitualCharge(int i) = 0; //r
	virtual int getRitualCost() = 0; //r
        virtual void setActPts(int i)=0;
        virtual int getActPts() const=0;
	virtual int getMaxActPts() const = 0;

        virtual void notify(const std::string event)=0; // m+r
	virtual void activate(std::shared_ptr<Card> target) =0; // spell  m
	virtual void activate()=0;  // spell m

	virtual void inspect() = 0; //
	virtual void popEnchant() = 0; //m
	virtual void addEnchant(std::shared_ptr<Card> c) = 0; //m
        virtual void attack(std::shared_ptr<Card> c) = 0; //m
	virtual void attack(Player *p) = 0;//m
	virtual void beAttacked(int i) = 0;//m
        virtual void setAbCost(int i) = 0;
        virtual void silence() = 0;
        

};

#endif
