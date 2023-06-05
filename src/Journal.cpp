#include "../include/Journal.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

Journal::Journal(string cheminBDD)
{
	this->cheminBDD = cheminBDD;
}

void Journal::enregistrerIMoteur(float intensite)
{
	ofstream fichier;
	/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
	fichier.open("/home/pi/valeurs/releve.csv", fstream::out | fstream::app);
	if (fichier)
	{
		fichier << intensite << endl;
		fichier.close();
	}
}

int Journal::enregistrerEvenement(int errcode, float valeur)
{
	ofstream fichier;
	string laDate;
	time_t tt;
	if (errcode == EVENMOTEUR)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);
		if (fichier)
		{
			using chrono::system_clock;
			system_clock::time_point today = system_clock::now();
			tt = system_clock::to_time_t(today);
			laDate = string(ctime(&tt));
			laDate = laDate.substr(0, laDate.length() - 1);
			fichier << laDate << " | Moteur bloqué. Intensité du courant: " << valeur << " mA." << endl;
			fichier.close();
			insererBDD(EVENMOTEUR, 0);
		}
		else
		{
			return -1;
		}
	}
	else if (errcode == EVENPRESENCE)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);
		if (fichier)
		{
			using chrono::system_clock;
			system_clock::time_point today = system_clock::now();

			tt = system_clock::to_time_t(today);
			laDate = string(ctime(&tt));
			laDate = laDate.substr(0, laDate.length() - 1);
			fichier << laDate << " | Cube absent : " << valeur << " ohm" << endl;
			fichier.close();
			insererBDD(EVENPRESENCE, 0);
		}
		else
		{
			return -1;
		}
	}
	else if (errcode == EVENBATTERIE)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);
		if (fichier)
		{
			using chrono::system_clock;
			system_clock::time_point today = system_clock::now();

			tt = system_clock::to_time_t(today);
			laDate = string(ctime(&tt));
			laDate = laDate.substr(0, laDate.length() - 1);
			fichier << laDate << " | Défaut batterie : " << valeur << " mA" << endl;
			fichier.close();
			insererBDD(EVENBATTERIE, 0);
		}
		else
		{
			return -1;
		}
	}
	else if ((errcode == EVENCONF) || (errcode == EVENDOUBLEHOR) || (errcode == EVENDOUBLEAR))
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);
		if (fichier)
		{
			using chrono::system_clock;
			system_clock::time_point today = system_clock::now();

			tt = system_clock::to_time_t(today);
			laDate = string(ctime(&tt));
			laDate = laDate.substr(0, laDate.length() - 1);
			fichier << laDate << " | Signaux cubes non conformes :  " << errcode << endl;
			fichier.close();
			insererBDD(EVENBATTERIE, 0);
		}
		else
		{
			return -1;
		}
	}
	else if (errcode == EVENCONNEXIONMOTEUR)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);
		if (fichier)
		{
			using chrono::system_clock;
			system_clock::time_point today = system_clock::now();

			tt = system_clock::to_time_t(today);
			laDate = string(ctime(&tt));
			laDate = laDate.substr(0, laDate.length() - 1);
			fichier << laDate << " | Défaut connexion ou alimentation moteur : " << valeur << " mA" << endl;
			fichier.close();
			insererBDD(EVENBATTERIE, 0);
		}
		else
		{
			return -1;
		}
	}
	return 0;
}

void Journal::enregistrerDefautConnexion(float valeur)
{
	int erreur = enregistrerEvenement(EVENCONNEXIONMOTEUR, valeur);
}

void Journal::enregistrerBlocage(float valeur)
{
	int erreur = enregistrerEvenement(EVENMOTEUR, valeur);
}

void Journal::enregistrerDonneesBatterie(float icourant, float tension)
{
	ofstream fichier;
	/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
	fichier.open("/home/pi/valeurs/relevesBatterie.csv", fstream::out | fstream::app);
	if (fichier)
	{
		fichier << icourant << ";" << tension << endl;
		fichier.close();
	}
}

void Journal::enregistrerFinEvenement(int errcode)
{
	ofstream fichier;
	string laDate;
	time_t tt;
	if (errcode == EVENMOTEUR)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);

		using chrono::system_clock;
		system_clock::time_point today = system_clock::now();
		tt = system_clock::to_time_t(today);
		laDate = string(ctime(&tt));
		laDate = laDate.substr(0, laDate.length() - 1);
		fichier << laDate << " | Fin blocage moteur " << endl;
		fichier.close();
		insererBDD(EVENMOTEUR, 0);
	}
	else if (errcode == EVENPRESENCE)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);

		using chrono::system_clock;
		system_clock::time_point today = system_clock::now();

		tt = system_clock::to_time_t(today);
		laDate = string(ctime(&tt));
		laDate = laDate.substr(0, laDate.length() - 1);
		fichier << laDate << " | Fin absence Cube" << endl;
		fichier.close();
		insererBDD(EVENPRESENCE, 0);
	}
	else if (errcode == EVENBATTERIE)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);

		using chrono::system_clock;
		system_clock::time_point today = system_clock::now();

		tt = system_clock::to_time_t(today);
		laDate = string(ctime(&tt));
		laDate = laDate.substr(0, laDate.length() - 1);
		fichier << laDate << " | Fin de problème batterie" << endl;
		fichier.close();
		insererBDD(EVENBATTERIE, 0);
	}
	else if (errcode == EVENCONF)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);

		using chrono::system_clock;
		system_clock::time_point today = system_clock::now();

		tt = system_clock::to_time_t(today);
		laDate = string(ctime(&tt));
		laDate = laDate.substr(0, laDate.length() - 1);
		fichier << laDate << " | Fin de problème signaux cube" << endl;
		fichier.close();
		insererBDD(EVENBATTERIE, 0);
	}
	else if (errcode == EVENCONNEXIONMOTEUR)
	{

		/* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
		fichier.open("/home/pi/Evenements/evenements.log", fstream::out | fstream::app);

		using chrono::system_clock;
		system_clock::time_point today = system_clock::now();

		tt = system_clock::to_time_t(today);
		laDate = string(ctime(&tt));
		laDate = laDate.substr(0, laDate.length() - 1);
		fichier << laDate << " | Fin défaut connexion ou alimentation moteur" << endl;
		fichier.close();
		insererBDD(EVENBATTERIE, 0);
	}
}

Journal::~Journal()
{
}

void Journal::insererBDD(int code, int valeur)
{
	cout << "on a bien inséré la donnée dans la BDD" << endl;
}