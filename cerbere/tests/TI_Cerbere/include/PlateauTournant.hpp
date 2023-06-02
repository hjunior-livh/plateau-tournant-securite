#include <exception>
using namespace std;

#ifndef __PlateauTournant_hpp__
#define __PlateauTournant_hpp__

//#include "Consigne.hpp"
#include "Signalement.h"
#include "Cerbere.hpp"
#include "Consigne.hpp"
#include  "Journal.hpp"

class PlateauTournant
{
private:
    bool estEnMouvementHoraire;
    bool estEnMouvementAntiHoraire;

    Signalement* lessignalements;
    Cerbere* laSecurite;
    Consigne* lesConsignes;
    Journal* lesJournaux;
public:
    PlateauTournant();
    bool getEstEnMouvementHoraire();
    bool getEstEnMouvementAntiHoraire();
    void verifications();
    void setEstEnMouvement(bool estEnMouvement);
    void tournerHoraire ();
    void tournerAntiHoraire();
    void timmobiliser();
    void signalerProbleme(int code);
};

#endif