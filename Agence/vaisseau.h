#pragma once
#include <string> 
#include "Faction.h"
#include "Station.h"
class Station;

class Vaisseau
{
protected:
	int attaque;
	int defense;
	int vie;
	int capacite;
	std::string nom;
	int niveau;
	int exp;
	std::string type;
	Faction* maFaction; 


public:
	Vaisseau(Faction* maFaction, std::string name);
	Vaisseau(int att, int def, int hp, int cap, int lvl, int ex, std::string name, Faction* maFaction);
	~Vaisseau();
	int getAtt();
	int getDef();
	int getVie();
	void setVie(int nouvelleVie);
	void Amelioration(Station* station);
	virtual std::string to_string();
	std::string genererNomAleatoire();
};

