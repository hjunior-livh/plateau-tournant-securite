#include <exception>
#include <math.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include "../include/Cerbere.hpp"

Cerbere::Cerbere(Consigne *consigne, Signalement *signalement, Journal *journal)
{

	leCourantMoteur = new C_courantMoteur();
	// Evolution à prévoir : lire les données de configuration de C_Force dans consigne
	_laPresence = new C_Force();
	_laFixation = new C_Fixation();
	this->consigne = consigne;
	signal = signalement;
	this->journal = journal;
	finRotation = true;
}

void Cerbere::setFinRotation(bool finRotation)
{
	this->finRotation = finRotation;
}
bool Cerbere::getFinRotation()
{
	return this->finRotation;
}

void Cerbere::lancerSurveillance()
{
	throw "Not yet implemented";
}

thread Cerbere::tVerifierCourant()
{
	return thread([this]
				  { verifierCourant(); });
}

void Cerbere::verifierCourant()
{
	int compteur = 0; // déclaration de plusieurs variables utiles au bon fonctionnement de la méthode.
	float seuilBlocageAlerte;
	float seuilBlocageMin;
	float seuilBlocageBranchement;

	consigne->obtenirSeuilsCourantMoteur(seuilBlocageMin, seuilBlocageAlerte, seuilBlocageBranchement); // on récupere nos seuils grace a la classe consigne.

	do
	{
		cout << "un" << endl;
		usleep(500000);
		leCourantMoteur->lire();					  // lecture du courant du moteur par le capteur.
		float iMoteur = leCourantMoteur->getReleve(); // iMoteur est une variable qui stocke la valeur retourné par getReleve .
		iMoteur = roundf(iMoteur);					  // iMoteur est arondi pour evité d'avoir trop de chiffres apres la virgule du relevé.
		journal->enregistrerIMoteur(iMoteur);

		if (iMoteur < 0) // le relevé est converti en valeur absolue pour faciliter le traitement derrière.
		{
			iMoteur = iMoteur * -1;
		}

		if ((iMoteur < seuilBlocageBranchement) && (finRotation == false)) // Si notre moteur a une tension trop basse et qu'il doit etre en mouvement
		{
			if (signal->getAlerterConnexionMoteur() == false)
			{
				journal->enregistrerDefautConnexion(iMoteur);
				signal->setAlerterConnexionMoteur(true);
				signal->signalerProbleme(Signalement::CONNEXIONMOTEUR); // c'est qu'il y a un probléme de branchement.
			}
		}
		else if ((iMoteur > seuilBlocageAlerte) && (finRotation == false))
		{					   // Si l'intensité du courant est superieure au seuil de blocage,
			compteur++;		   // on incremente notre variable compteur.
			if (compteur > 8) // Si notre compteur a été trop de fois incrementé,
			{
				if (signal->getAlerteMoteur() == false)
				{
					journal->enregistrerBlocage(iMoteur);
					signal->setAlerteMoteur(true);
					signal->signalerProbleme(Signalement::ALERTEMOTEUR); // on envoie un signal car c'est un blocage moteur, le moteur a trop de fois trop forcé.
				}
				compteur = 8; // on cape notre compteur pour ne pas qu'il s'envole.
			}
		}
		else
		{
			compteur--; // sinon, on rabaisse notre variable compteur de 1, on ne le met pas à 0 volontairement.

			if (compteur <= 0) // Si il devait etre inferieur a 0 il se remet à 0.
			{
				compteur = 0;
				if (signal->getAlerteMoteur() == true)
				{										 // si il y a eut un signalement et que le comportement est redevenu normal,
					signal->setAlerteMoteur(false);		 // on enleve le signalement
					journal->enregistrerFinEvenement(Signalement::ALERTEMOTEUR); // et on met dans le journal que l'evenement s'est terminée
				}
			}
			else if (signal->getAlerterConnexionMoteur()==true)
			{
				signal->setAlerterConnexionMoteur(false);
				journal->enregistrerFinEvenement(Signalement::CONNEXIONMOTEUR);

			}
		}
	} while (finRotation == false);
}

thread Cerbere::Tpresence()
{
	return thread([this]
				  { verifierPresence(); });
}

void Cerbere::verifierPresence()
{
	int nCapteur = 1;
	float Pied1, Pied2, seuilMin, seuilMax, seuilForcer, seuilPresenceMax;
	seuilMin = this->consigne->getSeuilmin();

	seuilMax = this->consigne->getSeuilmax();

	seuilForcer = this->consigne->getSeuilForcer();

	seuilPresenceMax = this->consigne->getSeuilPresenceMax();

	while (true)
	{

		nCapteur = 1;

		_laPresence->lire(nCapteur);

		Pied1 = _laPresence->getRelevePied1();

		nCapteur = 2;

		_laPresence->lire(nCapteur);

		Pied2 = _laPresence->getRelevePied2();

		if ((Pied1 > seuilMax) && (signal->getAlertePresence() == false))
		{

			this->journal->enregistrerEvenement(Journal::EVENPRESENCE, Pied1);

			this->signal->setAlertePresence(true);

			this->signal->signalerProbleme(Signalement::ALERTEPRESENCE);

			// le cube est pas present sur le plateau
		}
		else if ((Pied2 > seuilMax) && (signal->getAlertePresence() == false))
		{

			this->journal->enregistrerEvenement(Journal::EVENPRESENCE, Pied2);

			this->signal->setAlertePresence(true);

			this->signal->signalerProbleme(Signalement::ALERTEPRESENCE);
		}

		else if (((seuilMin < Pied1) && (Pied1 < seuilPresenceMax)) && ((seuilMin < Pied2) && (Pied2 < seuilPresenceMax)))

		{
			if (signal->getAlertePresence() == true)
			{
				this->journal->enregistrerFinEvenement(Journal::EVENPRESENCE);

				this->signal->setAlertePresence(false);
			}
			else if (signal->getAlerteForcer() == true)
			{
				this->journal->enregistrerFinEvenement(Journal::EVENFORCER);

				this->signal->setAlerteForcer(false);
			}

			// le cube est present sur le plateau
		}
		else if ((Pied1 < seuilForcer) && (signal->getAlerteForcer() == false))
		{

			this->journal->enregistrerEvenement(Journal::EVENFORCER, Pied1);
			this->signal->setAlerteForcer(true);
			this->signal->signalerProbleme(Signalement::ALERTEFORCER);
		}
		else if ((Pied2 < seuilForcer) && (signal->getAlerteForcer() == false))
		{

			this->journal->enregistrerEvenement(Journal::EVENFORCER, Pied2);
			this->signal->setAlerteForcer(true);
			this->signal->signalerProbleme(Signalement::ALERTEFORCER);
		}

		usleep(100000);
	}
}

void Cerbere::verifierFixation()
{
	throw "Not yet implemented";
}
