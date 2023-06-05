#include <iostream>
#include <unistd.h>
#include "../include/AlimentationBatterie.h"

int main()
{
    AlimentationBatterie tiAlimentationBatterie(23,0x44);

    char reponse ;
    std::cout<<"Voulez-vous actionner la charge ?o/n"<<std::endl;
    std::cin>>reponse;

    if(reponse == 'o')
    {
        std::cout<<"Lancement de la charge"<<std::endl;
        while (true){
            tiAlimentationBatterie.alimenter();
            tiAlimentationBatterie.releverDonneesCharge();
            tiAlimentationBatterie.obtenirDonnees();
            
            float CourantCharge = tiAlimentationBatterie.getCourant();
            std::cout << "Courant: " << CourantCharge << " A" << std::endl;

            float TensionCharge = tiAlimentationBatterie.getTension();
            std::cout << "Tension: " << TensionCharge << " V" << std::endl;
    
            usleep(1000000);
            }
    }
    else
    {
        tiAlimentationBatterie.couper();
    }
        
    return 0;
}