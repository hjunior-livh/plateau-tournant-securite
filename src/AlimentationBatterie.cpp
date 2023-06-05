#include "../include/AlimentationBatterie.h"
#include <unistd.h>

AlimentationBatterie::AlimentationBatterie(unsigned int pin, uint8_t address)
{
    monInterrupteur = new Interrupteur(pin);
    laCharge = new Charge(address);
}

void AlimentationBatterie::alimenter()
{
    monInterrupteur->actionner();

}

void AlimentationBatterie::releverDonneesCharge()
{
    usleep(10000);
    laCharge->lire();
}

void AlimentationBatterie::couper()
{
    monInterrupteur->desactiver();
}

void AlimentationBatterie::obtenirDonnees()
{
    courant = laCharge->getCourant();
    tension = laCharge->getTension();
}

float AlimentationBatterie::getCourant()
{
    return courant;
}

float AlimentationBatterie::getTension()
{
    return tension;
}

AlimentationBatterie::~AlimentationBatterie(){}