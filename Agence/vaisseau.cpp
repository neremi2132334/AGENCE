#include "vaisseau.h"
#include <iostream>
#include <string>

vaisseau::vaisseau(int attaque,int defense, int pv, int capacite, int lvl, int exp, std::string nom) 
{


}
vaisseau::~vaisseau()
{

}
std::string vaisseau::to_string()
{
	std::string stat;
	stat.append("Nom : " + nom);
	stat.append("Classe : " + classe);
	stat.append("\n Attaque :" + std::to_string(this->getAtt()) + "\n");
	stat.append(" Defense :" + std::to_string(this->getDef()) + "\n");
	stat.append(" Vie :" + std::to_string(this->getVie()) + "\n");
	stat.append(" Niveau :" + std::to_string(lvl) + "\n");
	stat.append(" exp :" + std::to_string(exp) + "\n");
	
	return stat;
}



int vaisseau::getAtt()
{
	return attaque;
}
int vaisseau::getDef()
{
	return defense;
}
int vaisseau::getVie()
{
	return pv;
}