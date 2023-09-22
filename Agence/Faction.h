#pragma once
#include <string>


class Faction
{
protected:

    int attaque;

    int defense;

    int pv;

    int capacite;

    std::string nom;


public:

    Faction();
    Faction(int att, int def, int pv, int capacite);

    std::string getNom();



};

