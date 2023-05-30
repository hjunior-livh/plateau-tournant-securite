#include <iostream>
#include <unistd.h>
#include <math.h>

#include "../include/PlateauTournant.hpp"


int main()
{
    /*
    Signalement *leSignalement = new Signalement();
    Consigne *consigne = new Consigne();

    Cerbere* cerbere = new Cerbere(consigne, leSignalement);
    cerbere -> verifierCourant(); */

    PlateauTournant *plateau = new PlateauTournant();
    plateau -> verifications();

    
}
