#ifndef C_COURANTMOTEUR_HPP
#define C_COURANTMOTEUR_HPP

#include "ina219.h"

class C_courantMoteur
{

private:
    float releve;
    INA219 *capteur;

public:
    C_courantMoteur();
    C_courantMoteur(char adresse);
    void lire();
    float getReleve();
    ~C_courantMoteur();
};

#endif // C_COURANTMOTEUR_H