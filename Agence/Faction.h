#pragma once
#include <string>
class Faction
{
protected:
	int attaque;
	int defense;
	int vie;
	int capacite;
	std::string nom;
public:
	Faction();
	Faction(std::string name);
	std::string getNom();
};

