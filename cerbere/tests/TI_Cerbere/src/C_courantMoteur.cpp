#include "../include/C_courantMoteur.hpp"
#include <iostream>

C_courantMoteur::C_courantMoteur() {
        float SHUNT_OHMS = 0.1;
        float MAX_EXPECTED_AMPS = 3.2;
        capteur = new INA219(SHUNT_OHMS, MAX_EXPECTED_AMPS);
        capteur -> configure(RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT);
        std::cout << "l'objet a été fait" << std::endl;
}

C_courantMoteur::~C_courantMoteur() {
        delete capteur;
}

float C_courantMoteur::getReleve() {
        std::cout << "le relevé est retourné" << std::endl;
        return releve;
}

void C_courantMoteur::lire() { 
        //std::cout << "nous allons lire" << std::endl;
        
        int out = 0;
        for(int i = 0; i < 5; i++)
        {
                out = out + capteur -> current();
                //usleep(500)
        }
        
        releve = out / 5;

        //std::cout << "lecture effectué" << std::endl;
}
