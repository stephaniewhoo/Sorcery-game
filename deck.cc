#include "deck.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <utility>
#include <fstream>
#include "airelem.h"
#include "earthelem.h"
#include "fireelem.h"
#include "potionsell.h"
#include "apprentice.h"
#include "novice.h"
#include "massum.h"
#include "bonegolem.h"
#include "banish.h"
#include "unsummon.h"
#include "recharge.h"
#include "disenchant.h"
#include "raisedead.h"
#include "blizzard.h"
#include "GiantStre.h"
#include "enrage.h"
#include "haste.h"
#include "MagicFati.h"
#include "Silence.h"
#include "darkritual.h"
#include "auraofpower.h"
#include "standstill.h"
#include "spell.h"
#include "ritual.h"
#include "auraofpower.h"


using namespace std;
class Card;

    Deck::  Deck (const string filename,Player *owner): owner{owner}{
        ifstream f{filename};
        string card;
        while (getline(f,card)) {
            addCard(card);
        }
    }

    Deck::  ~Deck(){

    }

    int Deck::decksize() {
        return content.size();
    }

    shared_ptr<Card> Deck:: popDeck() {
        shared_ptr<Card> temp = content.back();
        content.pop_back();
        return temp;
    }

    void Deck:: shuffle(){
        srand(time(NULL)); //
        for(unsigned int i = 0; i < content.size(); ++i){
            unsigned int r = rand() % content.size();
            swap(content[i],content[r]);
        }
    }

    void Deck:: addCard(const string s) {
	if(s == "Air Elemental"){
		content.emplace_back(make_shared<AirElem>(owner)); // new AirElem
	}else if(s == "Earth Elemental"){
			content.emplace_back(make_shared<EarthElem>(owner));
	}else if(s == "Bone Golem"){
			content.emplace_back(make_shared<BoneGol>(owner));
	}else if(s == "Fire Elemental"){
			content.emplace_back(make_shared<FireElem>(owner));
	}else if(s == "Potion Seller"){
			content.emplace_back(make_shared<PotionSell>(owner));
	}else if(s == "Novice Pyromancer"){
			content.emplace_back(make_shared<NovicePyro>(owner));
	}else if(s == "Apprentice Summoner"){
			content.emplace_back(make_shared<AppSum>(owner));
	}else if(s == "Master Summoner"){
			content.emplace_back(make_shared<MasSum>(owner));
	}else if(s == "Banish"){
			content.emplace_back(make_shared<Banish>(owner));
	}else if(s == "Unsummon"){
			content.emplace_back(make_shared<Unsummon>(owner));
	}else if(s == "Recharge"){
			content.emplace_back(make_shared<Recharge>(owner));
	}else if(s == "Disenchant"){
			content.emplace_back(make_shared<Disenchant>(owner));
	}else if(s == "Raise Dead"){
			content.emplace_back(make_shared<Raisedead>(owner));
	}else if(s == "Blizzard"){
			content.emplace_back(make_shared<Blizzard>(owner));
	}else if(s == "Giant Strength"){
			content.emplace_back(make_shared<GiantStre>(owner));
	}else if(s == "Enrage"){
			content.emplace_back(make_shared<Enrage>(owner));
	}else if(s == "Haste"){
			content.emplace_back(make_shared<Haste>(owner));
	}else if(s == "Magic Fatigue"){
			content.emplace_back(make_shared<MagicFati>(owner));
	}else if(s == "Silence"){
			content.emplace_back(make_shared<Silence>(owner));
	}else if(s == "Dark Ritual"){
			content.emplace_back(make_shared<DarkRitual>(owner));
	}else if(s == "Aura of Power"){
			content.emplace_back(make_shared<AuraOfPower>(owner));
	}else if(s == "Standstill"){
			content.emplace_back(make_shared<StandStill>(owner));
	}
}
    
