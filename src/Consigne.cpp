#include <unistd.h>
using namespace std;

#include "../include/Consigne.hpp"

Consigne::Consigne()
{
	seuilPresenceMin = 5000;
	seuilPresenceMax = 15000;
	seuilAbsence = 20000;
	seuilForcer = 3000;
	resitanceProtection = 21000;
	tensionAlimentation = 5;
	seuilBlocageMin = 10;
	seuilBlocageAlerte = 110;
	seuilBlocageBranchement = 2;
	seuiCourantChargeInvalide = 0.001;
	seuilCourantChargeValide = 0.08;
}

void Consigne::setValMinMot(float val)
{
	seuilBlocageMin = val;
}

void Consigne::setValMaxMot(float val)
{
	seuilBlocageAlerte = val;
}

float Consigne::getValMinMot()
{
	return seuilBlocageMin;
}

float Consigne::getValMaxMot()
{
	return seuilBlocageAlerte;
}

float Consigne::getValBranchementMot()
{
	return seuilBlocageBranchement;
}

void Consigne::obtenirSeuilsCourantMoteur(float &seuilBlocageMin, float &seuilBlocageAlerte, float &seuilBlocageBranchement)
{
	seuilBlocageMin = this->seuilBlocageMin;
	seuilBlocageAlerte = this->seuilBlocageAlerte;
	seuilBlocageBranchement = this->seuilBlocageBranchement;
}

void Consigne::obtenirSeuilsPresence(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax, float &seuilAbsence, float &seuilForcage)
{
	seuilPresenceCubeMin = this->seuilPresenceMin;
	seuilPresenceCubeMax = this->seuilPresenceMax;
	seuilAbsence = this->seuilAbsence;
	seuilForcage = this->seuilForcer;
}

bool Consigne::lireConsignes()
{
	throw "Not yet implemented";
}

float Consigne::getSeuilmin()
{
	return seuilPresenceMin;
}

float Consigne::getSeuilPresenceMax()
{
	return seuilPresenceMax;
}

float Consigne::getSeuilmax()
{
	return seuilAbsence;
}
float Consigne::getSeuilForcer()
{
	return seuilForcer;
}
float Consigne::getResitanceProtection()
{
	return resitanceProtection;
}
float Consigne::getTensionAlimentation()
{
	return tensionAlimentation;
}

float Consigne::getSeuiCourantChargeInvalide()
{
	return this->seuiCourantChargeInvalide;
}
float Consigne::getSeuilCourantChargeValide()
{
	return this->seuilCourantChargeValide;
}
float Consigne::getConsoOrdinateurBord()
{
	return this->consoOrdinateurBord;
}

Consigne::~Consigne()
{
}
