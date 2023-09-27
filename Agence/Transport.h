#pragma once
#include "Vaisseau.h"
class Transport : public Vaisseau
{
public: 
	Transport();
	Transport(Faction* maFaction, std::string name);
	~Transport();
	virtual std::string to_string();

};

