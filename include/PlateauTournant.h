#ifndef __PlateauTournant_h__
#define __PlateauTournant_h__

#include <string>
#include <thread>
using namespace std;

#include "Cerbere.hpp"
#include "Cube.h"
#include "Ares.h"
#include "Consigne.hpp"
#include "Signalement.h"

class Cube;
class Ares;

class PlateauTournant
{
private:
	Cerbere *_laSecurite;
	Cube *_leSegmentVol;
	Ares *_lOperation;
	Consigne *_lesConsignes;
	Signalement *_lessignalements;
	Journal *leJournal;
	bool estEnMouvementHoraire;	
	bool estEnMouvementAntiHoraire;		

public:
	PlateauTournant();
	~PlateauTournant();
	void tournerHoraire();
	void tournerAntiHoraire();
	void immobiliser();
	void signalerProbleme(int code);		
	Cerbere *getCerbere();
	Cube *getCube();
	Ares *getAres();
	Consigne *getConsigne();
	Signalement *getSignalement();
	void setCerbere(Cerbere *_laSecurite);
	void setCube(Cube *_leSegmentVol);
	void setAres(Ares *_lOperation);
	void setConsigne(Consigne *_lesConsignes);
	void setSignalement(Signalement *_lessignalements);
	bool getEstEnMouvementHoraire();
	bool getEstEnMouvementAntiHoraire();	
};

#endif
