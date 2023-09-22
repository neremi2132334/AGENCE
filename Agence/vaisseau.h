#pragma once
#include <iostream>

class vaisseau
{
protected :

    int valeurMarchande;

    int attaque;

    int defense;

    int pv;

    int capacite;

    std::string nom;

    int lvl;

    int exp;

    std::string classe;

public:

    vaisseau(int att, int def, int pv, int capacite, int lvl, int ex, std::string name);
    ~vaisseau();

    int getAtt();
    int getDef();
    int getVie();

    virtual std::string to_string();


};

