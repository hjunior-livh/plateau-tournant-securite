#include <iostream>
#include <unistd.h>
#include <math.h>

#include "../include/Journal.hpp"


int main()
{
    float intensite = 70.432978;
    Journal* journal = new Journal("~/BDD");

    journal -> enregistrerIMoteur(intensite);

    intensite  = 594058.4345;
    journal -> enregistrerEvenement(Journal::EVENMOTEUR,intensite);
}
