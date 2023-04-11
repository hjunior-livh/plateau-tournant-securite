#include <iostream>
#include <unistd.h>
#include <math.h>
#include "include/ina219.h"
#include "include/C_courantMoteur.hpp"

int main()
{
    C_courantMoteur *machin = new C_courantMoteur();
    machin->lire();
    int valeur = machin->getReleve();
    valeur = roundf(valeur);

    if (valeur >= -0.5 && valeur <= 0.5)
    {
        std::cout << "le moteur n'est pas bien branché ou est a l'arret" << std::endl;
    }
    if (valeur >= 15 && valeur <= 240)
    {
        std::cout << "Fonctionnement correct" << std::endl;
    }
    if (valeur >= 241)
    {
        std::cout << "le moteur force" << std::endl;
    }
}
