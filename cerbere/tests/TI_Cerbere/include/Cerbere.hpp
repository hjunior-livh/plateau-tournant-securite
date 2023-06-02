#ifndef CERBERE_HPP
#define CERBERE_HPP

//penser a inclure les 2 classe de William comme celle la:
#include "C_courantMoteur.hpp"
#include "Consigne.hpp"
#include "Signalement.h"
#include "Journal.hpp" 
#include <thread>


class Cerbere
{

private:
    //Chaques classes doivent declaré leurs pointeurs pour etre appele dans le constructeur de Cerbere
    C_courantMoteur* leCourantMoteur;
    Consigne* consigne;
    Signalement* signal;
    Journal* journal;
    bool finRotation;

public:
    Cerbere(Consigne* consigne, Signalement* signal, Journal* journal);
    void lanceSurveillance();
    void verifierPresence();
    void verifierFixation();
    thread tVerfierCourant();
    void verifierCourant();
    ~Cerbere();
};

#endif // CERBERE_HPP