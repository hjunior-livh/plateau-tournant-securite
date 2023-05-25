#include <exception>
#include <iostream>
using namespace std;

#include "Signalement.h"

Signalement::Signalement(){
	bool _alerteMoteur = false;
	bool _alerteBatterie = false;
	bool _alerteFixation = false;
	bool _alertePresence = false;
}

bool Signalement::getAlerteMoteur() {
	return this->_alerteMoteur;
}

void Signalement::setAlerteMoteur(bool aAlerteMoteur) {
	this->_alerteMoteur = aAlerteMoteur;
}

bool Signalement::getAlerteBatterie() {
	return this->_alerteBatterie;
}

void Signalement::setAlerteBatterie(bool aAlerteBatterie) {
	this->_alerteBatterie = aAlerteBatterie;
}

bool Signalement::getAlerteFixation() {
	return this->_alerteFixation;
}

void Signalement::setAlerteFixation(bool aAlerteFixation) {
	this->_alerteFixation = aAlerteFixation;
}

bool Signalement::getAlertePresence() {
	return this->_alertePresence;
}

void Signalement::setAlertePresence(bool aAlertePresence) {
	this->_alertePresence = aAlertePresence;
}
// Hypothése: chacun a ses codes d'erreurs pour le moment 
// afin d'avoir le bon cout lors des test
void Signalement::signalerProbleme(int code) {

	// Pour le courant moteur j'ai 2 cas. Mal branché et force trop donc
	// je prends le code 1 et 2. Le c'est quand il n'y a aucun probleme 
	// Donc rien a signalé

	if (code == 1) 
	{
		cout<<"le moteur est a l'arret"<<endl;
	}
	
	if (code == 2) 
	{
		cout<<"DANGER ! le moteur FORCE"<<endl;
	}
}


