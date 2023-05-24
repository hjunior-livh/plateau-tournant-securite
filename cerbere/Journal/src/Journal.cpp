#include <string>
#include <sqlite3.h>
#include "../include/Journal.hpp"


Journal::Journal(std::string cheminBDD) {
    this->cheminBDD = cheminBDD;
    this->
}

void Journal::insererBDD() {
    //
}

void Journal::enregistrer(int courantMoteur, unsigned long long int epochEnMs) {

}

void Journal::enregistrerDebutEvenement(std::string typeEvenement, int valeur, unsigned long long int epochEnMs) {

}

void Journal::enregistrerFinEvenement(std::string typeEvenement, unsigned long long int epochEnMs) {

}

void Journal::enregistrerDonneesBatterie(float courant, float tension, unsigned long long int epochEnMs) {
     
}

Journal::~Journal() {
    
}