#include <exception>
#include "../include/PlateauTournant.h"

PlateauTournant::PlateauTournant()
{
    _leSegmentVol = new Cube(this);
    _lesConsignes = new Consigne();
    _lessignalements = new Signalement();
	leJournal = new Journal("/home/pi/valeurs/journal.db");
    _lOperation = new Ares(_lessignalements, _lesConsignes, leJournal);	
    _laSecurite = new Cerbere(_lesConsignes, _lessignalements, leJournal);	
	estEnMouvementHoraire = false;
	estEnMouvementAntiHoraire = false;	   
}
PlateauTournant::~PlateauTournant()
{
}
void PlateauTournant::tournerHoraire()
{
	estEnMouvementHoraire = true;	
	estEnMouvementAntiHoraire = false;
	_laSecurite->setFinRotation(false); 
	_lOperation->tournerHoraire();
	thread verifierCourant = _laSecurite->tVerifierCourant();     
	verifierCourant.detach();  
			   
}
void PlateauTournant::tournerAntiHoraire()
{
	estEnMouvementHoraire = false;	
	estEnMouvementAntiHoraire = true;
	_laSecurite->setFinRotation(false); 
	_lOperation->tournerAntiHoraire();
	thread verifierCourant = _laSecurite->tVerifierCourant();     
	verifierCourant.detach();    
}
void PlateauTournant::immobiliser()
{
	estEnMouvementHoraire = false;	

	estEnMouvementAntiHoraire = false; 
	_lOperation->immobiliser();
	_laSecurite->setFinRotation(true);   
}
void PlateauTournant::signalerProbleme(int code)
{
	_lessignalements->signalerProbleme(code);
}
Cerbere *PlateauTournant::getCerbere()
{
	return _laSecurite;
}
Cube *PlateauTournant::getCube()
{
	return _leSegmentVol;
}
Ares *PlateauTournant::getAres()
{
	return _lOperation;
}
Consigne *PlateauTournant::getConsigne()
{
	return _lesConsignes;
}
Signalement *PlateauTournant::getSignalement()
{
	return _lessignalements;
}
void PlateauTournant::setCerbere(Cerbere *_laSecurite)
{
	this->_laSecurite = _laSecurite;
}
void PlateauTournant::setCube(Cube *_leSegmentVol)
{
	this->_leSegmentVol=_leSegmentVol;
}
void PlateauTournant::setAres(Ares *_lOperation)
{
	this->_lOperation=_lOperation;
}
void PlateauTournant::setConsigne(Consigne *_lesConsignes)
{
	this->_lesConsignes=_lesConsignes;
}
void PlateauTournant::setSignalement(Signalement *_lessignalements)
{
	this->_lessignalements=_lessignalements;
}
bool PlateauTournant::getEstEnMouvementHoraire()
{
    return estEnMouvementHoraire;
}
bool PlateauTournant::getEstEnMouvementAntiHoraire()
{
    return estEnMouvementAntiHoraire;
}