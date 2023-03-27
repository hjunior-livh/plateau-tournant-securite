#include "C_courantMoteur.hpp"
#include "ina219.h"

C_courantMoteur::C_courantMoteur() {
        float SHUNT_OHMS = 0.1;
        float MAX_EXPECTED_AMPS = 3.2;
        float INTERVAL = 10.0;
        INA219* capteur = new INA219(SHUNT_OHMS, MAX_EXPECTED_AMPS);
        capteur -> configure(RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT);
}

C_courantMoteur::~C_courantMoteur() {

}

float C_courantMoteur::getReleve() {
        
}

bool C_courantMoteur::lire() {
        float val = capteur -> current();
        if (val = ) 
}