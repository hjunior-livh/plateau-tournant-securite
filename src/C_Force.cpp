

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <unistd.h>

#include "../include/C_Force.hpp"

C_Force::~C_Force()
{
}
int C_Force::lire(int nCapteur)
{
        GPIO::I2C *i2c = new GPIO::I2C();

        i2c->open("/dev/i2c-1", adresseCAN);
        int data;

        if (nCapteur == 1)
        {

                data = 0x85D2;
        }
        else if (nCapteur == 2)
        {

                data = 0x85C2;
        }
        else
        {

                return -1;
        }

        int reg = 1;

        i2c->regwrite16(reg, data);

        data = i2c->regread16(reg);

        sleep(1);

        data = i2c->regread16(reg);

        reg = 0;

        data = i2c->regread16(reg);

        int datahigh = (data & 0x00FF) << 8;
        int datalow = data >> 8;
        data = datahigh | datalow;

        float myfloat;
        const float VPS = 4.096 / 32768;
        myfloat = data * VPS;

        float Rvar;
        float U = myfloat;

        Rvar = resistanceProtection * U / (tensionAlimentation- U);

        if (nCapteur == 1)
        {

                relevePied1 = Rvar;
        }
        if (nCapteur == 2)
        {

                relevePied2 = Rvar;
        }

        return 0;
}

C_Force::C_Force(char adresseCAN, float tensionAlimentation, float resistanceProtection)
{
        this->adresseCAN = adresseCAN;
        this->resistanceProtection = resistanceProtection;
        this->tensionAlimentation = tensionAlimentation;
}
float C_Force::getRelevePied1()
{
        return relevePied1;
}
float C_Force::getRelevePied2()
{
        return relevePied2;
}
