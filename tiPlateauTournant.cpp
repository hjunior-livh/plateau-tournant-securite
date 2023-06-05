#include <iostream>

#include "../include/Cube.h"
#include "../include/PlateauTournant.h"

using namespace std;

int main()
{
    char reponse;
    PlateauTournant *lePlateau = new PlateauTournant();
    Cube *leCube = new Cube(lePlateau);
    lePlateau->setCube(leCube);
    do
    {
        cout << "Voulez-vous :" << endl;
        cout << "-tourner dans le sens horaire (h)" << endl;
        cout << "- tourner dans le sens antihoraie (a) " << endl;
        cout << "- arrêter le moteur (s) pour mettre en charge la batterie" << endl;
        cout << "arrêter ici (o) " << endl;
        cin >> reponse;
        if (reponse == 'h')
        {
            lePlateau->tournerHoraire();
        }
        else if (reponse == 'a')
        {
            lePlateau->tournerHoraire();
        }
        else if (reponse == 's')
        {
            lePlateau->immobiliser();
        }
    } while (reponse != 'o');
}