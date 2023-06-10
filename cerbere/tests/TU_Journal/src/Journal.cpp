#include "../include/Journal.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

Journal::Journal(string cheminBDD)
{
}

void Journal::enregistrerIMoteur(float intensite)
{
    ofstream fichier;
    /* Cette fonction nécessite une amélioration afin d'adapter le chemin à l'installation*/
    // Obtention du temps actuel
    std::time_t t = std::time(nullptr);

    // Conversion en une structure tm locale
    std::tm *now = std::localtime(&t);

    // Récupération de la date au format DD/MM
    int day = now->tm_mday;
    int month = now->tm_mon + 1;    // L'index des mois commence à 0
    int year = now->tm_year + 1900; // L'année est stockée sous la forme d'une valeur depuis 1900

    // Récupération de l'heure au format HH:MM
    int hour = now->tm_hour;
    int min = now->tm_min;

    // transformation en string pour l'entete du fichier
    string annee = to_string(year);
    string mois = to_string(month);
    string jour = to_string(day);
    string heure = to_string(hour);
    string minute = to_string(min);

    string laDate = annee + "_" + mois + "_" + jour + "__" + heure + "_" + minute;
    laDate = "/home/pi/valeurs/releves_" + laDate + ".csv";

    fichier.open(laDate, fstream::out | fstream::app); // releves_YYYY_MM_DD__HH_MM.csv
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
}

void Journal::enregistrerDefautConnexion(float valeur)
{
    //
}

void Journal::enregistrerBlocage(float valeur)
{
    //
}

void Journal::enregistrerDonneesBatterie(float courant, float tension)
{
}

void Journal::enregistrerFinEvenement(int errcode)
{
    //
}

Journal::~Journal()
{
}

void Journal::insererBDD(int code, int valeur)
{
    cout << "on a bien inséré la donnée dans la BDD" << endl;
}