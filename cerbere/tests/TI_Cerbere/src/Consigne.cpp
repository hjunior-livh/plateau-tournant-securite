#include <iostream>

#include "../include/Consigne.hpp"

Consigne::Consigne(){
    seuilBlocageMin = 10;
    seuilBlocageAlerte = 150;
    seuilBlocageBranchement = 2;
}

void Consigne::setValMinMot(float val){
    seuilBlocageMin = val;
}

void Consigne::setValMaxMot(float val){
    seuilBlocageAlerte = val;
}

float Consigne::getValMinMot() {
    return seuilBlocageMin;
}

float Consigne::getValMaxMot() {
    return seuilBlocageAlerte;

}

float Consigne::getValBranchementMot() {
    return seuilBlocageBranchement;
}

void Consigne::obtenirSeuillCourantMoteur(float &seuilBlocageMin, float &seuilBlocageAlerte, float &seuilBlocageBranchement){
    seuilBlocageMin = this -> seuilBlocageMin;
    seuilBlocageAlerte = this -> seuilBlocageAlerte;
    seuilBlocageBranchement= this -> seuilBlocageBranchement;

}


float Consigne::obtenirSeuillPrésenceMoteur(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax){
    return 0;
}