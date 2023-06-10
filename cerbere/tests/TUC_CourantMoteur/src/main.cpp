#include <iostream>
#include <unistd.h>
#include <math.h>
#include "../include/ina219.h"
#include "../include/C_courantMoteur.hpp"
// #include "../include/signalement.hpp"

int main()
{
    C_courantMoteur *machin = new C_courantMoteur();
    std::cout << "L'obet C_courantMoteur à été fait" << std::endl;
    machin->lire();
    int valeur = machin->getReleve();
    valeur = roundf(valeur);

    std::cout <<"La valeur mesuré est: "<< valeur << std::endl;

    if (valeur < 0) // le relevé est converti en valeur absolue pour faciliter le traitement derrière.
    {
        valeur = valeur * -1;
    }

    if (valeur >= 0 && valeur <= 10)
    {
        std::cout << "Le moteur n'est pas bien branché ou est a l'arret" << std::endl;
    }
    if (valeur >= 10 && valeur <= 125)
    {
        std::cout << "Fonctionnement correct" << std::endl;
    }
    if (valeur >= 126)
    {
        std::cout << "Le moteur force" << std::endl;
    }
}
