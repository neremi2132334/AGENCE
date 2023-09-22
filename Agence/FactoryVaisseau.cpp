#include "FactoryVaisseau.h"
#include "vaisseau.h"
#include <vector> 
#include <string>  
#include <cstdlib>
#include <ctime>

int genererNb(int min, int max) {
    return rand() % (max - min + 1) + min;
}


vaisseau* FactoryVaisseau::getRandomVaisseau()
{
    srand(time(0));
    int attaque = genererNb(5, 20);
    int defense = genererNb(5, 20);
    int pv = genererNb(10, 50);
    int capacite = genererNb(20, 100);
    int lvl = genererNb(1, 10);
    int exp = genererNb(0, 100);

    std::vector<std::string> shipNames = {
        "Liberator", "Myrmidon", "Insurgent", "Night", "Fade", "STS Pennsylvania",
        "SS Immortal", "BS Traveler", "HMS Juggernaut", "HWSS Vanquisher",
        "Trident", "Bastion", "Reliant", "Karma", "Panama", "SC Warrior",
        "STS Immortal", "HMS Stormspike", "HMS Deonida", "ISS Utopia",
        "Stalker", "Anarchy", "Invader", "Immortal", "ISS NATHAN", "HWSS Alice",
        "USS Lancaster", "ISS Storm", "STS Raving", "HMS Deinonychus"
    };

    int randomIndex = rand() % shipNames.size();
    std::string nom = shipNames[randomIndex];

    return new vaisseau(attaque, defense, pv, capacite, lvl, exp, nom);
}


Faction* FactoryVaisseau::getRandomFaction()
{
    srand(time(0));
    int attaque = genererNb(5, 10);
    int defense = genererNb(5, 10);
    int pv = genererNb(10, 30);
    int capacite = genererNb(20, 60);
    std::string nom = "Faction_" + std::to_string(genererNb(1, 50));
    return new Faction(attaque, defense, pv, capacite);
}

