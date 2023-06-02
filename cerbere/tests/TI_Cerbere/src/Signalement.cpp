#include <exception>
using namespace std;

#include "../include/Signalement.h"

bool Signalement::getAlerteMoteur()
{
	return this->_alerteMoteur;
}

void Signalement::setAlerteMoteur(bool aAlerteMoteur)
{
	this->_alerteMoteur = aAlerteMoteur;
}

bool Signalement::getAlerteBatterie()
{
	return this->_alerteBatterie;
}

void Signalement::setAlerteBatterie(bool aAlerteBatterie)
{
	this->_alerteBatterie = aAlerteBatterie;
}

bool Signalement::getAlerteFixation()
{
	return this->_alerteFixation;
}

void Signalement::setAlerteFixation(bool aAlerteFixation)
{
	this->_alerteFixation = aAlerteFixation;
}

bool Signalement::getAlertePresence()
{
	return this->_alertePresence;
}

void Signalement::setAlertePresence(bool aAlertePresence)
{
	this->_alertePresence = aAlertePresence;
}

bool Signalement::getAlerteSignauxNonconformes()
{
	return this->_alerteSignauxNonconformes;
}
bool Signalement::getAlerteOrdreDoubleHoraire()
{
	return this->_alerteOrdreDoubleHoraire;
}
bool Signalement::getAlerteOrdreDoubleAntiHorairee()
{
	return this->_alerteOrdreDoubleAntiHoraire;
}

void Signalement::setAlerteSignauxNonconformese(bool aalerteSignauxNonconformes)
{
	this->_alerteSignauxNonconformes = aalerteSignauxNonconformes;
}

void Signalement::setAlerteOrdreDoubleHoraire(bool alerteOrdreDoubleHoraire)
{
	this->_alerteOrdreDoubleHoraire = alerteOrdreDoubleHoraire;
}
void Signalement::setAlerteOrdreDoubleAntiHorairee(bool aalerteOrdreDoubleAntiHoraire)
{
	this->_alerteOrdreDoubleAntiHoraire = aalerteOrdreDoubleAntiHoraire;
}

void Signalement::signalerProbleme(int code)
{
	if (code == SIGNONCONF)
		_alerteSignauxNonconformes = true;
	else if (code == SIGNONDOUBLEHOR)
		_alerteOrdreDoubleHoraire = true;
	else if (code == SIGNONDOUBLEAR)
		_alerteOrdreDoubleAntiHoraire = true;
	else if (code == ALERTEMOTEUR)
		_alerteMoteur = true;
	else if (code == ALERTEBATTERIE)
		_alerteBatterie = true;
	else if (code == ALERTEFIXATION)
		_alerteFixation = true;
	else if (code == ALERTEPRESENCE)
		_alertePresence = true;
	raise(SIGUSR1);
}
