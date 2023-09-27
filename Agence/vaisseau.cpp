#include "Vaisseau.h"
#include "Utilitaire.h"
#include "Station.h"
#include <string>
#include <vector>
#include <iostream>


Vaisseau::Vaisseau(int att, int def, int hp, int cap, int lvl, int ex, std::string name, Faction* faction)
{
	attaque = att;
	defense = def;
	vie = hp;
	niveau = lvl;
	exp = ex;
	nom = name;
}
Vaisseau::Vaisseau(Faction* faction, std::string name)
{
	attaque = Utilitaire::genererNb(3, 10);
	defense = Utilitaire::genererNb(3, 8);
	vie = Utilitaire::genererNb(50, 100);
	niveau = Utilitaire::genererNb(1, 3);
	exp = Utilitaire::genererNb(1, 1000);
	nom = name;
	maFaction = faction;
}


Vaisseau::~Vaisseau() {}

std::string Vaisseau::to_string()
{
	std::string info;
	info.append("Nom :" + nom + "\n");
	info.append("Attaque :" + std::to_string(this->getAtt()) + "\n");
	info.append("Defense :" + std::to_string(this->getDef()) + "\n");
	info.append("Vie :" + std::to_string(this->getVie())  + "\n");
	info.append("Niveau:" + std::to_string(niveau) + "\n");
	info.append("exp :" + std::to_string(exp) + "\n");


	return info; 
}

int Vaisseau::getAtt()
{
	return attaque;
}
int Vaisseau::getDef()
{
	return defense;
}
int Vaisseau::getVie()
{
	return vie;
}

void Vaisseau::setVie(int nouvelleVie)
{
	vie = nouvelleVie;
}

std::string Vaisseau::genererNomAleatoire()
{
	std::vector<std::string> shipNames = {
		 "ISS MomImOnMars", "Myrmidon", "USS ChildSupport", "CtrlAltDefeat", "HMS Shetookthekid", "STS Cummer",
		"SS Trump", "DivorceForce", "HMS PRICE INC", "HWSS OopsForgotTheFuel",
		"MissedTheEx-it", "Bastien", "BleuNordique", "Civic 2003", "Panama", "SC Warrior",
		"STS Immortal", "ISS BonhommeCarnaval","HMS Jerome", "ISS Utopia",
		"Stalker", "HMS Sand Nude", "Invader", "Mangue Mauve", "ISS NATHAN", "HWSS Aliceau",
		"USS SEESHARP", "LacSaint-Jean", "STS Dragqueen", "HMS Kenoghetto"
	};

	int randomIndex = Utilitaire::genererNb(0, shipNames.size());
	return shipNames[randomIndex];
}
void Vaisseau::Amelioration(Station* station)
{
    int choix;

    std::cout << "1. Ameliorer l'attaque (cout = 5 platiniums)" << std::endl;
    std::cout << "2. Ameliorer la defense (cout = 3 platiniums)" << std::endl;

    std::cout << "Entrez votre choix: ";
    std::cin >> choix;

    int coutAttaque = 5;
    int coutDefense = 3;

    switch (choix) {
    case 1:
        if (station->platiniumDispo >= coutAttaque) {
            std::cout << "Les stats d'attaques sont améliorées." << std::endl;
            attaque += 3;
            station->platiniumDispo -= coutAttaque;
        }
        else {
            std::cout << "Pas assez de platinium pour cette amélioration." << std::endl;
        }
        break;
    case 2:
        if (station->platiniumDispo >= coutDefense) {
            std::cout << "Vous avez choisi d'ameliorer la défense du vaisseau." << std::endl;
            defense += 2;
            station->platiniumDispo -= coutDefense;
        }
        else {
            std::cout << "Pas assez de platinium pour cette amélioration." << std::endl;
        }
        break;
    default:
        std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
    }
}

