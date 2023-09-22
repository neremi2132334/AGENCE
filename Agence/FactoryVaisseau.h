#pragma once
#include "vaisseau.h"  
#include "Faction.h"   


class FactoryVaisseau
{

public:
    static vaisseau* getRandomVaisseau();

private:
    static Faction* getRandomFaction();

};


