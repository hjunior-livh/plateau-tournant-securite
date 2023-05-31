#include "../include/Cerbere.hpp"

#include <iostream>
#include <math.h>


Cerbere::Cerbere(Consigne* consigne,Signalement* signalement){
    
    leCourantMoteur = new C_courantMoteur();
    signal = signalement;
    this -> consigne = consigne;

}

void Cerbere::lanceSurveillance(){

}

thread Cerbere::tVerfierCourant(){
    return thread([this]{
        verifierCourant();
    });
}


void Cerbere::verifierCourant(){
    while (true){

        leCourantMoteur -> lire();
        float iMoteur = leCourantMoteur -> getReleve();
        iMoteur = roundf(iMoteur); 
        if (iMoteur < 0){
            iMoteur = iMoteur * -1;
        } 
    
        float seuilBlocageAlerte; //consigne -> getValMaxMot();
        float seuilBlocageMin;
        float seuilBlocageBranchement;// consigne -> getValBranchementMot();
    
        consigne -> obtenirSeuillCourantMoteur(seuilBlocageMin,seuilBlocageAlerte,seuilBlocageBranchement);


        if (iMoteur < seuilBlocageBranchement){
            signal -> signalerProbleme(4);
        } 
        if ( iMoteur > seuilBlocageAlerte ){
            signal -> signalerProbleme(4);
        }
    }
}

void Cerbere::verifierPresence(){

}
void Cerbere::verifierFixation(){

}

Cerbere::~Cerbere() {
    delete  leCourantMoteur;
}
