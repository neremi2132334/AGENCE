#include "Faction.h"
Faction::Faction() :attaque(0), defense(0), vie(0), capacite(0)
{

}
Faction::Faction(std:: string name)
{
	if (name == "ATM")
	{
		attaque = 1;
		defense = 1;
		vie = 1;
		capacite = 1;
		nom = name;
	}
	else if (name == "ROUGE")
	{
		attaque = 5;
		defense = 10;
		vie = 20;
		capacite = 3;
		nom = name;
	}
	else
	{
		attaque = 10;
		defense = 5;
		vie = 20;
		capacite = 3;
		nom = name;
	}
}

std::string Faction::getNom()
{
	return nom;
}
