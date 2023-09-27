#include "Livraison.h"
#include "Vaisseau.h"
Livraison::Livraison() :Vaisseau(3,15,100,10,5,5000,"VaisseL", maFaction)
{
	type = "Livraison";
};

Livraison::Livraison(Faction* maFaction, std::string name) : Vaisseau(maFaction, name)
{
	type = "Livraison";
};

Livraison::~Livraison() {}

std::string Livraison::to_string()
{
	return Vaisseau::to_string() + "Type de vaisseau : Guerre\n";
}
