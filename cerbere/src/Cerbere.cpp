#include "../include/Cerbere.hpp"

#include <iostream>
#include <math.h>

Cerbere::Cerbere(){
    cMoteur = new C_courantMoteur();
    consigne = new Consigne();
    signal = new Signalement();

}

void lanceSurveillance(){

}

void Cerbere::verifierCourant(){
    cMoteur -> lire();
    float iMoteur = cMoteur -> getReleve();
    iMoteur = roundf(iMoteur); 
    if (iMoteur < 0){
        iMoteur = iMoteur * -1;
    } 
    if (iMoteur > consigne -> getValMaxMot())
    {
        //Début de l'alerte
        //std::cout << "DANGER ! Le motteur force trop. Intensité du moteu = " << iMoteur << " mA" << std::endl;
        signal -> signalerProbleme(2);
    }
    if (iMoteur < consigne -> getValMinMot())
    {   
        //FIN de l'alerte
        //std::cout << "re passage a la normal. Intensité du moteur = " << iMoteur << " mA" << std::endl;
        signal -> signalerProbleme(1);
    }
}

void verifierPresence(){

}
void verifierFixation(){

}

Cerbere::~Cerbere() {
    delete cMoteur;
}
