#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <string>
#include <fstream>
using namespace std;

class Journal
{

private:
    string cheminBDD;

    /// @brief Methode qui permetra de traduire nos fichiers textes d'evenement
    /// ou csv de log en SQLite pour les envoyé a la BDD.
    /// @param code En fonction du code on sait quel evenement ou log on souhaite envoyé
    /// à la BDD.
    /// @param valeur les evenements doivent etre dans les journaux avec
    /// leurs valeurs. Pour des envoies de log dans la BDD ce champ doit etre à 0.
    void insererBDD(int code, int valeur);

public:

	static const int EVENCONF = 1;
	static const int EVENDOUBLEHOR = 2;
	static const int EVENDOUBLEAR = 3;
	static const int EVENMOTEUR = 4;
	static const int EVENBATTERIE = 5;
	static const int EVENFIXATION = 6;
	static const int EVENPRESENCE = 7;
	static const int EVENCONNEXIONMOTEUR = 8;
	static const int LOGIMOTEUR = 9;
	static const int EVENFORCER = 10;	

    /// @brief met la valeur de intensite du courant dans un fichier csv
    /// afin de faire le graphique de la tension sur l'IHM.
    /// @param intensite valeur du courant du moteur a écrire dans chaques lignes.
    void enregistrerIMoteur(float intensite);


    /// @brief creation de journaux avec horodatage qui montre le début d'un évenement.
    /// @param errcode Chaques problemes du systeme a son code erreur. Journal::"le code"
    /// @param EVENCONF 
    /// @param EVENDOUBLEHOR 
    /// @param EVENDOUBLEAR 
    /// @param EVENMOTEUR 
    /// @param EVENBATTERIE 
    /// @param EVENFIXATION 
    /// @param EVENPRESENCE 
    /// @param EVENCONNEXIONMOTEUR  
    /// @param LOGIMOTEUR 
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
