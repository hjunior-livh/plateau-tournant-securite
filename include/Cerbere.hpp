#include <exception>
#include <thread>
using namespace std;

#ifndef __Cerbere_h__
#define __Cerbere_h__

#include "../include/C_courantMoteur.hpp"
#include "../include/C_Fixation.hpp"
#include "../include/C_Force.hpp"
#include "../include/Journal.hpp"
#include "../include/Consigne.hpp"
#include "../include/Signalement.h"

/**
 * Classe generale de l'application de diagnostic et securite du plateau.
 * Fournit les thread de gestion de la securite
 */
class Cerbere
{
private:
	C_courantMoteur *leCourantMoteur;
	C_Fixation *_laFixation;
	C_Force *_laPresence;
	Journal *journal;
	Consigne *consigne;
	Signalement *signal;
    bool finRotation;

	void lancerSurveillance();

public:
	/// @brief méthode de création du thread de surveillance du courant
	/// @return un thread (non pointeur)
	thread tVerifierCourant();

private:
	/// @brief méthode de surveillance du courant
	void verifierCourant();

public:
	/// @brief méthode de création du thread de surveillance de la présence du Cube
	/// @return un thread (non pointeur)
	thread Tpresence();

private:
	/// @brief méthode vérification de la présence du cube
	void verifierPresence();

public:
	void verifierFixation();

public:
	Cerbere(Consigne *aConsigne, Signalement *aSignalement, Journal *aJournal);
	void setFinRotation(bool finRotation);
	bool getFinRotation();	
};

#endif
