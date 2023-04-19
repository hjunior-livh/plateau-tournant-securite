#include "../include/Cerbere.hpp"


#include <iostream>


Cerbere::Cerbere(){
    CMoteur = new C_courantMoteur();
}

void lancéSurveillance(){

}

void Cerbere::vérifierCourant(){
    std::cout << "on lance la lecture" << std::endl;
    CMoteur -> lire();
    std::cout << "valeure relevé: ";
    CMoteur -> getReleve();
    std::cout << std::endl;
}

void vérifierPrésence(){

}
void vérifierFixation(){

}

Cerbere::~Cerbere() {
    delete CMoteur;
}
