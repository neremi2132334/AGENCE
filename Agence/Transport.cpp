#include "Transport.h"
#include "Vaisseau.h"
Transport::Transport():Vaisseau(5,10,100,20,3,1200, "VaisseauT", maFaction)
{
	type = "Transport";
};

Transport::Transport(Faction* maFaction, std::string name) : Vaisseau(maFaction, name)
{
	type = "Transport";
};

Transport::~Transport(){}

std::string Transport::to_string()
{
	return Vaisseau::to_string() + "Type de vaisseau : Guerre\n";
}

