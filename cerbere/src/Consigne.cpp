#include <iostream>

#include "../include/Consigne.hpp"

Consigne::Consigne(){
    
}

void Consigne::setValMinMot(int val){
    seuilBlocageMin = val;
}

void Consigne::setValMaxMot(int val){
    seuilBlocageAlerte = val;
}

int Consigne::getValMinMot() {
    return seuilBlocageMin;
}

int Consigne::getValMaxMot() {
    return seuilBlocageAlerte;

}

float obtenirSeuillCourantMoteur(float &seuilBlocageMin, float &euilBlocageMax);


float obtenirSeuillCourantMoteur(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax);