#include <iostream>
#include <unistd.h>
#include <math.h>
#include "include/ina219.h"
#include "include/C_courantMoteur.hpp"

int main()
{
    C_courantMoteur *machin = new C_courantMoteur();
    while(true){
        machin->lire();
        int valeur = machin->getReleve();
        valeur = roundf(valeur);
        std::cout << valeur << std::endl;
        usleep(100);
    }
}
