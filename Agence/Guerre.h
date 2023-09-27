#pragma once
#include "Vaisseau.h"
class Guerre : public Vaisseau
{
public:
	Guerre();
	Guerre(Faction* maFaction, std::string name);
	~Guerre();
	virtual std::string to_string();

};

