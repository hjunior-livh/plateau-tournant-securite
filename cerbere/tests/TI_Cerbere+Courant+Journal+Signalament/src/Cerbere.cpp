#include "../include/Cerbere.hpp"
#include <math.h>
#include <exception>
#include <unistd.h>
#include <iostream>


Cerbere::Cerbere(Consigne *consigne, Signalement *signalement, Journal *journal)
{

    leCourantMoteur = new C_courantMoteur();
    signal = signalement;
    this->consigne = consigne;
    this->journal = journal;
    finRotation = true;
}

void Cerbere::lanceSurveillance()
{
}

thread Cerbere::tVerfierCourant()
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
		float iMoteur;
		int i=0;

		do{
		leCourantMoteur->lire();					  // lecture du courant du moteur par le capteur.
		iMoteur = leCourantMoteur->getReleve(); // iMoteur est une variable qui stocke la valeur retourné par getReleve .
		iMoteur = roundf(iMoteur);					  // iMoteur est arondi pour evité d'avoir trop de chiffres apres la virgule du relevé.

		journal->enregistrerIMoteur(iMoteur);

		if (iMoteur < 0) // le relevé est converti en valeur absolue pour faciliter le traitement derrière.
		{
			iMoteur = iMoteur * -1;
		}

		
		if(iMoteur > seuilBlocageBranchement){
			break;
		}	

		usleep(10000);
		i++;
		}while(i < 50);

		if(i > 50){
			journal->enregistrerDefautConnexion(iMoteur);
			signal->setAlerterConnexionMoteur(true);
			signal->signalerProbleme(Signalement::CONNEXIONMOTEUR); // c'est qu'il y a un probléme de branchement avant le démarage.
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

void Cerbere::verifierPresence()
{
}
void Cerbere::verifierFixation()
{
}

void Cerbere::setfinRotation(bool etatFinRotation)
{
	finRotation = etatFinRotation;
}

Cerbere::~Cerbere()
{
    delete leCourantMoteur;
}
