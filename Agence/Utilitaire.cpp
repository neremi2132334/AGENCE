#include "Utilitaire.h"
#include <iostream>

int Utilitaire::genererNb(int min, int max)
{
	srand(time(NULL));
	return (rand() % (max - min + 1)) + min;
}