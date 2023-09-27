#pragma once
#include "Vaisseau.h"
class Livraison : public Vaisseau
{
public:
	Livraison();
	Livraison(Faction* maFaction, std::string name);
	~Livraison();
	virtual std::string to_string();
};

