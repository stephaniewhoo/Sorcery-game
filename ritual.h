#ifndef RITUAL_H
#define RITUAL_H
#include <memory>
#include "player.h"
#include "card.h"
class Ritual : public Card {
    protected:
   int charge; // life
   int actCost;
   public:
   Ritual(std::string name, std::string type, std::string des, int cost, Player *owner,int charges, int actCost);
   virtual~Ritual();
   int getAttack()const override;
   void setAttack(int i)override;
   int getDefence()const override;
   void setDefence(int i)override;
   int getAbCost() override;
   std::vector<std::shared_ptr<Card>> getEnchants() override;
   void inspect() override;
   void popEnchant()override;
   void addEnchant(std::shared_ptr<Card> c)override;
   void attack(std::shared_ptr<Card> c)override;
   void attack(Player *p)override;
   void beAttacked(int i)override;
   void activate(std::shared_ptr<Card> target);// spell or active ability
   void activate();// ab
   void setAbCost(int i) override;  
   void setActPts(int i) override;
   int getActPts() const override;
   void silence() override;
   int getMaxActPts() const override; 
   int getRitualCost()override;
   int getRitualCharge()const override;
   void setRitualCharge(int i)override;
   virtual void notify(const std::string event)=0;
   void incActPts() override;
};

#endif
