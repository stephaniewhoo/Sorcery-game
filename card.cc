#include "card.h"
#include "player.h"
using namespace std;

Card:: Card(string name, string type, string des,int cost,Player* p): name{name},type{type},des{des},cost{cost},owner{p}{}

Card::~Card(){}

string Card::getName()const{
	return name;
}

string Card::getType()const{
	return type;
}

string Card::getDes() const {
	return des;
}

int Card::getCost()const{
	return cost;
}


Player *Card::getOwner()const{
	return owner;
}

void Card::setCost(int i){
	cost = i;
}

