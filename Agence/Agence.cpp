
#include "vaisseau.h"
#include <string>


int main()
{
    srand(time(NULL));
    std::cout << "... production d'un vaisseau" << std::endl;
    vaisseau * Fusee = new vaisseau(5, 6, 12, 100, 1, 0, "fiat multiplat");
    std::cout << Fusee->to_string();
    delete Fusee;
}

