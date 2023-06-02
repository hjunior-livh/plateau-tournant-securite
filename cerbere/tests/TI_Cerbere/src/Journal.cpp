#include "../include/Journal.hpp"
#include <string>
#include <fstream>

using namespace std;

Journal::Journal(string cheminBDD){

}

void Journal::enregistrerIMoteur(float intensite){
    ofstream fichier;
    fichier.open ("releve.csv", std::fstream::out | std::fstream::app);
    fichier << intensite << std::endl;
}

int Journal::enregistrerEvenement(int errcode, float valeur){

}

void Journal::enregistrerDefautConnexion(float valeur){

}

void Journal::enregistrerBlocage(float valeur){

}

void Journal::enregistrerDonneesBatterie(float courant, float tension){

}

void Journal::enregistrerFinEvenement(int errcode){

}

Journal::~Journal(){
    
}

void Journal::insererBDD(){

}