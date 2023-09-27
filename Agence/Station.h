#pragma once
#include <string> 
#include <vector>
#include "Vaisseau.h"

using std::vector;
class Vaisseau;

class Station
{

protected:
	int vieStation;

public:
	int platiniumDispo;
	vector<Vaisseau*> vecVaisseau;
	Station();
	~Station();
	Vaisseau* getVaisseauDispo();
	void init(Faction* maFaction);
	void AjouterVaisseau(Faction* maFaction);
	void AjouterVaisseau(Vaisseau* vaisseau);
	void Combat(Vaisseau* monVaisseau, Vaisseau* vaisseau);

	virtual std::string to_string();
	int getVie();
	int getPlat();
};

