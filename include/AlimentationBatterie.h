
#ifndef __AlimentationBatterie_h__
#define __AlimentationBatterie_h__

#include "Charge.hpp"
#include "Interrupteur.h"

class AlimentationBatterie
{
    private : 
    Charge *laCharge;
    Interrupteur *monInterrupteur;

    float courant;
    float tension;

    public :

    //Pour simplifier le constructeur certains arguments on une valeur par défaut.
    AlimentationBatterie(unsigned int pin,uint8_t address);
    void alimenter();
    void releverDonneesCharge();
    void couper();
    void obtenirDonnees();
    float getCourant();
    float getTension();

    ~AlimentationBatterie();



};

#endif
