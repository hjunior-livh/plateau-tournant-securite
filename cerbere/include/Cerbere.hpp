#ifndef CERBERE_HPP
#define CERBERE_HPP

//penser a inclure les 2 classe de William comme celle la:
#include "C_courantMoteur.hpp" 

class Cerbere
{

private:
    //Chaques classes doivent déclaré leurs pointeurs pour etre appelé dans le constructeur de Cerbere
    C_courantMoteur* CMoteur;

    int iMoteur;
    void vérifierCourant();

public:
    Cerbere();
    void lancéSurveillance();
    void vérifierPrésence();
    void vérifierFixation();
    ~Cerbere();
};

#endif // CERBERE_HPP