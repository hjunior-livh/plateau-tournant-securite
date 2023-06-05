#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "../include/SignalCube.hpp"

using namespace GPIO;

SignalCube::~SignalCube(void)
{
	// Le destructeur ne fait rien ici
}


void SignalCube::triggered(unsigned int gpio)
{
	if (gpio == signal1.get_pin())
	{
		if (!signal1.triggered())
			return;
	}
	else if (gpio == signal2.get_pin())
	{
		if (!signal2.triggered())
			return;
	}

	if ((signal1.get_state() == 1) && (signal2.get_state() == 0))
	{
		anomalie++;
		if (anomalie <= seuil)
		{
			conforme = false;
			return;
		}
		else 
		{
			// Plateau Tournant immobile
			_plateauTournant->signalerProbleme(1);
			_plateauTournant->immobiliser();
			return;
		}		
	}
	if ((signal1.get_state() == 0) && (signal2.get_state() == 0))
	{

		anomalie++;
		if (anomalie <= seuil)
		{
			conforme = false;
			return;
		}
		else 
		{
			// Plateau Tournant immobile
			_plateauTournant->signalerProbleme(1);
			_plateauTournant->immobiliser();
			return;
		}		
	}

	// Si les deux signaux sont conformes:
	anomalie = 0;

	conforme = true;

	decoder_ordre();
}

void SignalCube::decoder_ordre()
{
	if (signal1.get_state() == 1) 
	{
		if (_plateauTournant->getEstEnMouvementAntiHoraire())
		{
			// Plateau Tournant immobile -  ordre de fin de rotation
			_plateauTournant->immobiliser();
		}
		else if (!_plateauTournant->getEstEnMouvementHoraire())
		{
			// sens horaire
			_plateauTournant->tournerHoraire();			
		}
		else
		{
			// Plateau Tournant immobile
			_plateauTournant->signalerProbleme(2);
			_plateauTournant->immobiliser();
		}
	}
	else
	{
		// sens anti horaire
		if (_plateauTournant->getEstEnMouvementHoraire())
		{
			// Plateau Tournant immobile -  ordre de fin de rotation
			_plateauTournant->immobiliser();
		}
		else if (!_plateauTournant->getEstEnMouvementAntiHoraire())
		{
			// sens horaire
			_plateauTournant->tournerAntiHoraire();			
		}			

		else
		{
			// Plateau Tournant immobile
			_plateauTournant->signalerProbleme(3);
			_plateauTournant->immobiliser();
		}
	}

}

void SignalCube::setSignal1(DigitalIn aSignal1)
{
	this->signal1 = aSignal1;
}

DigitalIn SignalCube::getSignal1()
{
	return this->signal1;
}

void SignalCube::setSignal2(DigitalIn aSignal2)
{
	this->signal2 = aSignal2;
}

DigitalIn SignalCube::getSignal2()
{
	return this->signal2;
}

void SignalCube::setPlateauTournant(PlateauTournant *plateauTournant)
{
	this->_plateauTournant = plateauTournant;
}

PlateauTournant *SignalCube::getPlateauTournant()
{
	return this->_plateauTournant;
}
