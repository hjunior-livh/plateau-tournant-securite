#include "../include/Journal.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

Journal::Journal(string cheminBDD){

}

void Journal::enregistrerIMoteur(float intensite){
    ofstream fichier;
    fichier.open ("~/valeurs/releve.csv", fstream::out | fstream::app);
    fichier << intensite << endl;
    fichier.close();
    insererBDD(Journal::LOGIMOTEUR,intensite);
}

int Journal::enregistrerEvenement(int errcode, float valeur){
    if (errcode == EVENMOTEUR)
    {
        ofstream fichier;
        fichier.open ("~/Evenements/evenements.log", fstream::out | fstream::app);
        using chrono::system_clock;
        system_clock::time_point today = system_clock::now();
	    time_t tt;
	    tt = system_clock::to_time_t ( today );
	    fichier << ctime(&tt) << " | Moteur bloqué. Intensité du courant: "<< valeur << " mA.";
        fichier.close();
        insererBDD(EVENMOTEUR,valeur);
    }
}

void Journal::enregistrerDefautConnexion(float valeur){
    //
}

void Journal::enregistrerBlocage(float valeur){
    //
}

void Journal::enregistrerDonneesBatterie(float courant, float tension){

}

void Journal::enregistrerFinEvenement(int errcode){
    //
}

Journal::~Journal(){
    
}

void Journal::insererBDD(int code, int valeur){
    cout<<"on a bien inséré la donnée: "<< valeur << " dans la BDD."<<endl;
}