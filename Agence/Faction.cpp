#include "Faction.h"
#include "FactoryVaisseau.h"
#include <iostream>
#include <string>

Faction::Faction(int att, int def, int pv, int capacite)
    : attaque(att), defense(def), pv(pv), capacite(capacite), nom("Fiat Multipla")
{
    
}

std::string Faction::getNom()
{
	return nom;
}
