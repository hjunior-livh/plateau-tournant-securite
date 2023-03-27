#include <iostream>
#include <unistd.h>
#include <math.h>
#include "src/ina219.h"

int main()
{
    float SHUNT_OHMS = 0.1;
    float MAX_EXPECTED_AMPS = 3.2;
    float INTERVAL = 10.0; //
    while (true)
    {
        INA219 i(SHUNT_OHMS, MAX_EXPECTED_AMPS);
        i.configure(RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT);
        while (true)
        {
            float current = i.current();
            std::cout << (roundf(current * 1000) / 1000) /* << " mA" */ << std::endl;
            usleep(INTERVAL * 1000);
        }
    }
}


