#pragma once

class C_courantMoteur
{

private:
    float releve();
    INA219 *capteur;

public:
    C_courantMoteur();
    C_courantMoteur(char adresse);
    bool lire();
    float getReleve();
    ~C_courantMoteur();
};