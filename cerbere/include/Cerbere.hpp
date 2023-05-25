#ifndef CERBERE_HPP
#define CERBERE_HPP

//penser a inclure les 2 classe de William comme celle la:
#include "C_courantMoteur.hpp"
#include "Consigne.hpp"
#include "Signalement.h"

class Cerbere
{

private:
    //Chaques classes doivent declaré leurs pointeurs pour etre appele dans le constructeur de Cerbere
    C_courantMoteur* cMoteur;
    Consigne* consigne;
    Signalement* signal;

public:
    Cerbere();
    void lanceSurveillance();
    void verifierPresence();
    void verifierFixation();
    void verifierCourant();
    ~Cerbere();
};

#endif // CERBERE_HPP