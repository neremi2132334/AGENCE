#include <iostream>
#include <ctime>
#include "Faction.h"
#include "FactoryVaisseau.h"
#include "Station.h"
#include <conio.h>
int menu(Faction* maFaction, Station* maStation);


int main()
{
    int choixFaction(0);
    Faction* faction;
    Station* maStation = new Station();
    std::cout << "Bienvenue sur Star Wish..." << std::endl;
    std::cout << "Choix de votre Faction !" << std::endl;
    while (choixFaction < 1 || choixFaction > 3)
    {
        std::cout <<
            "1- ATM -> Cette Faction est la plus faible pour un mode jeux plus difficile\n"
            "2- BLEUE -> Cette Faction est plus booster sur l'attaque et moins la défense\n"
            "3- ROUGE-> Cette Faction est plus booster sur la défense et moins sur l'attaque" << std::endl;

        std::cin >> choixFaction;
    }
    switch (choixFaction)
    {
    case 1: std::cout << "Vous etes la Faction ATM" << std::endl; faction = new Faction("ATM"); break;
    case 2: std::cout << "Vous etes la Faction BLEUE" << std::endl; faction = new Faction("BLEUE"); break;
    case 3: std::cout << "Vous etes la Faction ROUGE" << std::endl; faction = new Faction("Rouge"); break;

    default: std::cout << "Vous etes la Faction BLEUE" << std::endl; faction = new Faction("BLEUE"); break;
    }

    while (maStation->getVie() != 0)
    {
        menu(faction, maStation);
    }
    








    /*srand(time(NULL));
    std::cout << ".... production d'un vaisseau" << std::endl;
    Vaisseau* monVaisseau = FactoryVaisseau::getRandomVaisseau();
    std::cout << monVaisseau->to_string();

    delete monVaisseau;*/


};

int menu(Faction* maFaction, Station* maStation)
{
    int choix;
    Vaisseau* vaisseau;
    Vaisseau* vaisseauEnnemi;
    Faction* factionEnnemi = new Faction("ARGGG");


    std::cout << std::endl;
    std::cout << "Que voulez-vous faire ?" << std::endl;
    std::cout << "1. Combattre des mercenaires" << std::endl;
    std::cout << "2. Ameliorer le vaisseau" << std::endl;
    std::cout << "3. Ajouter des Vaisseaus a la Station" << std::endl;
    std::cout << "4. Voir les Stats de sa Station" << std::endl;



    std::cout << "Entrez votre choix:";
    std::cin >> choix;



    switch (choix) {
    case 1:
        std::cout << "Vous avez choisi de combattre." << std::endl;
        
        vaisseauEnnemi = FactoryVaisseau::getRandomVaisseau(factionEnnemi);
        vaisseau = maStation->getVaisseauDispo();
        maStation->Combat(vaisseau, vaisseauEnnemi);
        break;
    case 2:
        std::cout << "Vous avez choisi d'ameliorer le vaisseau." << std::endl;
        vaisseau = maStation->getVaisseauDispo();
        vaisseau->Amelioration(maStation);

        break;
    case 3:
        std::cout << "Vous avez choisi d'Ajouter des Vaisseaux a votre station." << std::endl;
        maStation->AjouterVaisseau(maFaction); 
        break;
    case 4:
        std::cout << "Voici les stats de votre Station \n" + maStation->to_string() << std::endl;
        break;
    default:
        std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
        return menu(maFaction, maStation);
    }



    return choix;
}