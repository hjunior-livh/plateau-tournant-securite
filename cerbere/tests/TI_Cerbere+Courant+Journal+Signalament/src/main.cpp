#include <iostream>
#include <unistd.h>
#include <math.h>
#include <exception>

#include "../include/Signalement.h"
#include "../include/Cerbere.hpp"
#include "../include/Consigne.hpp"
#include  "../include/Journal.hpp"


int main()
{
    //déclaration des objets
    Cerbere* laSecurite;
    Signalement* lessignalements;
    Consigne* lesConsignes;
    Journal* lesJournaux;

    lessignalements = new Signalement();
    lesConsignes = new Consigne();
    lesJournaux = new Journal("~/BDD");
    laSecurite = new Cerbere(lesConsignes,lessignalements,lesJournaux);

    //début algorithme
    std::cout << "lancement de la verification du courant "<< std::endl;
    laSecurite -> setfinRotation(false);
    thread courant = laSecurite -> tVerfierCourant();
    courant.detach();
    usleep(8000000);
    laSecurite -> setfinRotation(true);
    std::cout << "fin du programme" << std::endl;
}