

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

#include "include/cppgpio/i2c.hpp"
#include "include/cppgpio/C_Force.hpp"


using namespace std;
using namespace GPIO;

int main()
{
int nCapteur;
float relevePied;

C_Force *c_force = new C_Force();

cout << "creation de l'objet "<< c_force <<endl;
do {

    cout << "Saisier le numero du capteur entre 1 ou 2"<<endl;
    cin >> nCapteur;

    cout<<nCapteur<<endl;
    c_force->lire(nCapteur);

    if (nCapteur==1)
        relevePied = c_force->getRelevePied1();

    if (nCapteur==2)
        relevePied = c_force->getRelevePied2();

    cout << "La resitance du capteur n" << dec << nCapteur << " est de Rpied " << relevePied << "Ω" << endl;
}
while ((nCapteur == 1) || (nCapteur ==2));

cout << "Valeur saisie incorrecte." << endl;
}
