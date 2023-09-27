#include "FactoryVaisseau.h"
#include "Utilitaire.h"
#include "Faction.h"
#include "Transport.h"
#include "Guerre.h"
#include "Livraison.h"

Vaisseau* FactoryVaisseau::getRandomVaisseau(Faction* maFaction)
{
	Vaisseau* vaisseau(0);
	//Faction* maFaction = getRandomFaction();
	std::string nom = vaisseau->genererNomAleatoire();


	int nb = Utilitaire::genererNb(1, 3);
	if (nb == 1)
		vaisseau = new Transport(maFaction, nom);
	else if (nb == 2)
		vaisseau = new Guerre(maFaction, nom);
	else
		vaisseau = new Livraison(maFaction, nom);

	return vaisseau;
}

Faction* FactoryVaisseau::getRandomFaction()
{
	Faction* faction(0);
	

	int nb = Utilitaire::genererNb(1, 3);
	if (nb == 1)
		faction = new Faction("ATM");
	else if (nb == 2)
		faction = new Faction("ROUGE");
	else
		faction = new Faction("BLEUE");

	return faction;
}


