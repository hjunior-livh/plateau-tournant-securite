#include <exception>
#include <thread>
#include <chrono>
using namespace std;

#ifndef __Ares_h__
#define __Ares_h__

#include "Moteur.h"
#include "HautParleur.h"
#include "Signalisation.h"
#include "AlimentationBatterie.h"
#include "Sauvegarde.h"
#include "Position.h"
#include "Cube.h"
#include "Signalement.h"
#include "Consigne.hpp"
#include "Journal.hpp"

class Ares
{
private:
	Moteur *_lePilote;
	HautParleur *_leSonore;
	Signalisation *_laSignalisation;
	AlimentationBatterie *_lAlimentationB;
	Sauvegarde *_laSauvegarde;
	Position *_laPosition;
	Consigne *_laConsigne;
	Signalement *_leSignalement;
	Journal *_leJournal;

public:
	void alimenterBatterie();

public:
	thread tAlimenterBatterie();

public:
	void commuterAlimentation();

public:
	void mesurerCourantCharge();

public:
	void alerteChargeOn();

public:
	void alerteChargeOff();

public:
	void tournerHoraire();

public:
	void tournerAntiHoraire();

public:
	void immobiliser();

public:
	Ares(Signalement* aSignalement, Consigne* aConsigne, Journal* aJournal);
	~Ares();
};

#endif
