#include <exception>
using namespace std;

#ifndef __PlateauTournant_hpp__
#define __PlateauTournant_hpp__

#include "Consigne.hpp"
#include "Signalement.h"
#include "Cerbere.hpp"

class PlateauTournant
{
private:
    bool estEnMouvementHoraire;
    bool estEnMouvementAntiHoraire;
public:
    PlateauTournant();
    bool getEstEnMouvementHoraire();
    bool getEstEnMouvementAntiHoraire();
    void setEstEnMouvement(bool estEnMouvement);
    void tournerHoraire ();
    void tournerAntiHoraire();
    void timmobiliser();
    void signalerProbleme(int code);
};

#endif