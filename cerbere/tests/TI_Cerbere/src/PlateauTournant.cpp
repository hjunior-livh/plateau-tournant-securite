#include "../include/PlateauTournant.hpp"

#include <iostream>



PlateauTournant::PlateauTournant(){
    lessignalements = new Signalement();
    lesConsignes = new Consigne();
    laSecurite = new Cerbere(lesConsignes,lessignalements);

    estEnMouvementHoraire = false;
    estEnMouvementAntiHoraire = false;
}

bool PlateauTournant::getEstEnMouvementHoraire(){
    return estEnMouvementHoraire;
}

bool PlateauTournant::getEstEnMouvementAntiHoraire(){
    return estEnMouvementAntiHoraire;
}

void PlateauTournant::setEstEnMouvement(bool estEnMouvement){

}

void PlateauTournant::verifications(){
    laSecurite -> verifierCourant();
}

void PlateauTournant::tournerHoraire (){

}

void PlateauTournant::tournerAntiHoraire(){

}

void PlateauTournant::timmobiliser(){

}

void PlateauTournant::signalerProbleme(int code){

}
