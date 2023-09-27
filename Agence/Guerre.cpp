#include "Guerre.h"
#include "Vaisseau.h"


Guerre::Guerre() :Vaisseau(10,8,100,3,3,1200, "VaisseauG", maFaction)
{
	type = "Guerre";
};

Guerre::Guerre(Faction* maFaction, std::string name) : Vaisseau(maFaction, name)
{
	type = "Guerre";
};

Guerre::~Guerre() {}

std::string Guerre::to_string()
{
	return Vaisseau::to_string() + "Type de vaisseau : Guerre\n";
}