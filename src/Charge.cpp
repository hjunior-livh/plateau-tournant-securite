#include "../include/Charge.hpp"
#include <unistd.h>

Charge::Charge(uint8_t address)
{
    leCapteur = new INA219(0.1, 2, address);
    leCapteur->configure(RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT);
}

void Charge::lire(){
    laTension = leCapteur->voltage();
    leCourant = leCapteur->current()/1000;
    sleep(1);
}

float Charge::getTension()
{
    return laTension;
}

float Charge::getCourant()
{
    return leCourant;
}

Charge::~Charge(){}
