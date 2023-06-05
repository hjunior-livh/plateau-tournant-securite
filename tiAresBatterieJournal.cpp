#include <iostream>

#include "../include/Ares.h"
#include "../include/Consigne.hpp"
#include "../include/Journal.hpp"
#include "../include/Signalement.h"
#include "../include/Cube.h"
#include "../include/PlateauTournant.h"

using namespace std;

int main()
{
    char reponse;
    Consigne *consigne = new Consigne();
    Signalement *signalement = new Signalement();
    Journal *journal = new Journal("~/valeurs/journal.db");

    Ares *lOperation = new Ares(signalement, consigne, journal);
    do {
    cout << "Voulez-vous :" << endl;  
    cout << "-tourner dans le sens horaire (h)" << endl;
    cout << "- tourner dans le sens antihoraie (a) " << endl;
    cout << "- arrêter le moteur (s) pour mettre en charge la batterie" << endl;
    cout << "- simplement commuter l'alimentation (c) " << endl;
    cout << "- simplement mesurer le courant de charge batterie (m) ?" << endl;
    cout << "arrêter ici (o) " << endl;
    cin >> reponse;
    if (reponse == 'h')
    {
        lOperation->tournerHoraire();
    }
    else if (reponse == 'a')
    {
        lOperation->tournerHoraire();
    }
    else if (reponse == 's')
    {
        lOperation->immobiliser();
    }
    else if (reponse == 'c')
    {
        lOperation->commuterAlimentation();
    }    
    else if (reponse == 'm')
    {
        lOperation->mesurerCourantCharge();
    } 

    } while ( reponse != 'o');

    
}