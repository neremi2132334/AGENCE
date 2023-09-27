#include "Station.h"
#include "FactoryVaisseau.h"
#include "Utilitaire.h"
#include <vector>
#include <iostream>

//RIEN COMPRIS DEMANDER A VINCENT


using std::vector;
Station::Station()
{
	vieStation = 1000;
	platiniumDispo = 50; 
};

Station::~Station() {

}
Vaisseau* Station::getVaisseauDispo()
{
	int cpt = 1;
	for (Vaisseau* vaisseau : vecVaisseau)
	{
		std::cout << cpt << std::endl;
		std::cout << vaisseau->to_string() << std::endl;
		cpt++;
	}

	int choix(0);
	while(choix >= 0 && choix < vecVaisseau.size())
	{
		std::cout << "Choisissez un vaisseau en entrant son index: " << std::endl;
		std::cin >> choix;
	}
	return vecVaisseau[choix -1];

}

void Station::AjouterVaisseau(Faction* maFaction)
{
	int choixVaisseau(0);
	Vaisseau* monVaisseau;
	while (choixVaisseau < 1 || choixVaisseau > 2)
	{
		std::cout << "Voulez-vous ajouter un vaisseau a votre station pour 20 Platinium ? (1- OUI / 2- Non) " << std::endl;
		std::cin >> choixVaisseau;
	}
	switch (choixVaisseau) {
	case 1:
		std::cout << "Vaisseau Ajouter Pour 20 Platinium." << std::endl;
		platiniumDispo -= 20;

		monVaisseau = FactoryVaisseau::getRandomVaisseau(maFaction);
		vecVaisseau.push_back(monVaisseau);
		break;
	case 2:
		std::cout << "Ajout d'un vaisseau annuler ! " << std::endl;
		break;
	default:
		std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
		break;
	}
}

void Station::AjouterVaisseau(Vaisseau* vaisseau)
{
	vecVaisseau.push_back(vaisseau);
}

void Station::Combat(Vaisseau* monvaisseau, Vaisseau* vaisseau)
{
	std::cout << "Le combat commence maintenant..." << std::endl;
	std::cout << "Vaisseau Ennemi \n" + vaisseau->to_string() << std::endl;
	std::cout << "Votre Vaisseau \n"+ monvaisseau->to_string() << std::endl;
	while (monvaisseau->getVie() > 0 && vaisseau->getVie() > 0)
	{
		// Tour du joueur
		int degatsJoueur = monvaisseau->getAtt() - vaisseau->getDef();
		int chanceDeBlocageEnnemi = Utilitaire::genererNb(0, 100);

		if (chanceDeBlocageEnnemi < vaisseau->getDef())
		{
			std::cout << "L'ennemi bloque votre attaque !" << std::endl;
		}
		else
		{
			int chanceCritique = Utilitaire::genererNb(0, 100);
			if (chanceCritique < 5)  
			{
				degatsJoueur *= 2;
				std::cout << "Coup critique de l'ennemi !" << std::endl;
			}
			if (degatsJoueur < 0) degatsJoueur = 0; 
			vaisseau->setVie(vaisseau->getVie() - degatsJoueur);
			std::cout << "Vous infligez " << degatsJoueur << " points de degats. --> Vie restante de l'ennemi: " << vaisseau->getVie() << std::endl;
		}


		// Tour de l'ennemi
		int degatsEnnemi = vaisseau->getAtt() - monvaisseau->getDef();
		int chanceDeBlocageJoueur = Utilitaire::genererNb(0, 100);

		if (chanceDeBlocageJoueur < monvaisseau->getDef())
		{
			std::cout << "Vous bloquez l'attaque de l'ennemi !" << std::endl;
		}
		else
		{
			int chanceCritique = Utilitaire::genererNb(0, 100);
			if (chanceCritique < 5)  
			{
				degatsEnnemi *= 2;
				std::cout << "Coup critique de l'ennemi !" << std::endl;
			}
			if (degatsEnnemi < 0) degatsEnnemi = 0; 
			monvaisseau->setVie(monvaisseau->getVie() - degatsEnnemi);
			std::cout << "L'ennemi vous inflige " << degatsEnnemi << " points de degats. Votre vie restante: " << monvaisseau->getVie() << std::endl;
		}


		if (vaisseau->getVie() <= 0)
		{
			std::cout << "Vous avez gagne ! +10 platinium !" << std::endl;
			platiniumDispo += 10;
			monvaisseau->setVie(monvaisseau->getVie() + 10);
			delete vaisseau;
			return;
		}

		if (monvaisseau->getVie() <= 0)
		{
			std::cout << "Vous avez perdu le combat. Votre vaisseau est detruit." << std::endl;
			delete monvaisseau;
			return;
		}
	}
   
}

void Station::init(Faction* maFaction)
{
	for (int i = 0; i < 3; i++)
	{
		vecVaisseau.push_back(FactoryVaisseau::getRandomVaisseau(maFaction));
	}
}

std::string Station::to_string()
{
	std::string info;
	info.append("Vie de Votre Station :" + std::to_string(this->getVie()) + "\n");
	info.append("Votre Platinium :" + std::to_string(this->getPlat()) + "\n");
	return info;
}

int Station::getVie()
{
	return vieStation;
}
int Station::getPlat()
{
	return platiniumDispo;
}