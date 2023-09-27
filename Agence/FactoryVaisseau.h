#pragma once
#include "Vaisseau.h"
#include "Faction.h"
class FactoryVaisseau
{
public: 
	static Vaisseau* getRandomVaisseau(Faction* maFaction);

private:
	static Faction* getRandomFaction();
};

