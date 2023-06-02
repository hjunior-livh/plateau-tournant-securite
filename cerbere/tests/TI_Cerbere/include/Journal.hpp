#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <string>
#include <fstream>
using namespace std;

class Journal
{

private:
    string cheminBDD;
    void insererBDD();

public:
    /// @brief met la valeur de intensite du courant dans un fichier csv
    /// afin de faire le graphique de la tension sur l'IHM.
    /// @param intensite valeur du courant du moteur a écrire dans chaques lignes.
    void enregistrerIMoteur(float intensite);


    /// @brief creation de journaux avec horodatage qui montre le début d'un évenement.
    /// @param errcode Chaques problemes du systeme a son code erreur.
    /// @param valeur va permettre de voir la valeur mesuré qui déclanche l'évenement
    int enregistrerEvenement(int errcode, float valeur);

    Journal(std::string cheminBDD);

    /// @brief creation de journaux avec horodatage qui montre la fin d'un évenement.
    /// @param errcode Chaques problemes du systeme a son code erreur
    void enregistrerFinEvenement(int errcode);

    void enregistrerDonneesBatterie(float courant, float tension);

    /// @brief On enregistre le blocage du moteur avec la date dans un journal evenement 
    /// car on appelle la methode enregistrerEvenement
    /// @param valeur va permettre de voir la valeur mesuré qui déclanche l'évenement.
    void enregistrerBlocage(float valeur);
    
    /// @brief On enregistre le defaut d'alimentation du moteur avec la date dans un   
    /// journal evenement car on appelle la methode enregistrerEvenement
    /// @param valeur va permettre de voir la valeur mesuré qui déclanche l'évenement.
    void enregistrerDefautConnexion(float valeur);

    ~Journal();
};

#endif
