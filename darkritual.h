#ifndef DARK_RITUAL_H
#define DARK_RITUAL_H
#include "ritual.h"

class DarkRitual :public Ritual {
    public:
    DarkRitual(Player *owner);
    ~DarkRitual();
    void notify(const std::string event) override;
};

#endif
