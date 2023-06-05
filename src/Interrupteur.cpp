#include "../include/Interrupteur.h"

Interrupteur::Interrupteur(unsigned int pin)
{
    actionneur = new GPIO::DigitalOut(pin);
}

void Interrupteur::actionner()
{
    actionneur->on();
    on = true;
}

void Interrupteur::desactiver()
{
    actionneur->off();
    on = false;
}

bool Interrupteur::getEtat()
{
    return on;
}

Interrupteur::~Interrupteur()
{
    
}