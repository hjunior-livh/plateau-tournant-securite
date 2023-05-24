#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <string>
#include <sqlite3.h>


class Journal {

    private:
        std::string cheminBDD;
        
        void insererBDD();
    public:
        Journal(std::string cheminBDD);
        ~Journal();
        void enregistrer(int courantMoteur, unsigned long long int epochEnMs);                                     // l'argument courantMoteur est passé de float à int car le courant est mesuré en mA
        void enregistrerDebutEvenement(std::string typeEvenement, int valeur, unsigned long long int epochEnMs);   //
        void enregistrerFinEvenement(std::string typeEvenement, unsigned long long int epochEnMs);                 //
        void enregistrerDonneesBatterie(float courant, float tension, unsigned long long int epochEnMs);           //
};

#endif //JOURNAL_HPP