#include <exception>
using namespace std;

#ifndef __Consigne_h__
#define __Consigne_h__

class Consigne
{
private:
    /// @brief Attributs consignes de la présence cube en ohm
    float seuilPresenceMin;
    float seuilPresenceMax;
    /// @brief attribut seuil d'absence cube en ohm
    float seuilAbsence;
    /// @brief attribut seuil au dessous duquel un surpoids est détecté en ohm
    float seuilForcer;
    /// @brief résistance de protection ajustable des capteurs de force en ohm
    float resitanceProtection;
    /// @brief tension d'alimentation de l'étage capteur de force en V
    float tensionAlimentation;
    /// @brief seuil de détection min d'un blocage moteur en mA
    float seuilBlocageMin;
    /// @brief seuil de détection Max d'un blocage moteur en mA
    float seuilBlocageAlerte;
    /// @brief seuil de détection d'un problème de branchement en mA
    float seuilBlocageBranchement;
    /// @brief seuil en dessous duquel une erreur de connexion est établie
    float seuiCourantChargeInvalide;
    /// @brief seuil en dessus duquel la charge est en cours (0,5 A si SegmentVol allumé; 0,08 A si SegmentVol éteint
    ///- fonctionnement normal => redémarrage par carte gestion charge quand la charge est terminée)
    float seuilCourantChargeValide;
    float consoOrdinateurBord;

public:
    Consigne();
    /// @brief lit les consignes dans un fichier de consignes
    /// @return true si lecture réussie
    bool lireConsignes();
    /// @brief permet de récupérer les 3 paramètres en lien avec le blocage/branchement moteur
    /// @param seuilBlocageMin = seuil minimum de blocage du moteur en mA
    /// @param seuilBlocageAlerte = seuil d'alerte blocage en mA
    /// @param seuilBlocageBranchement = seuil de détection d'un problème de branchement en mA
    void obtenirSeuilsCourantMoteur(float &seuilBlocageMin, float &seuilBlocageAlerte, float &seuilBlocageBranchement);
    /// @brief Méthode simplifiée de récupération des seuils de présence Cube
    /// @param seuilPresenceCubeMin en ohm
    /// @param seuilPresenceCubeMax en ohm
    /// @param seuilAbsence en ohm
    /// @param seuilForcage en ohm
    void obtenirSeuilsPresence(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax, float &seuilAbsence, float &seuilForcage);
    /// @brief fournit le seuil à partir duquel le poids présent est considéré comme étant celui du Cube.
    /// @return valeur du seuilPresenceMin
    float getSeuilmin();
    /// @brief fournit le seuil Maximum à partir duquel le Cube doit être admis comme absent lors de l'enlèvement.
    /// @return seuilAbsence
    float getSeuilmax();
    /// @brief fournit le seuil à partir duquel le Cube est admis comme présent lors de la pose
    /// @return seuilPresenceMax
    float getSeuilPresenceMax();
    /// @brief fournit le seuil à partir duquel le poids est considéré comme supérieur à celui du cube
    /// @return seuilForcer
    float getSeuilForcer();
    float getResitanceProtection();
    float getTensionAlimentation();
    void setValMinMot(float val);
    void setValMaxMot(float val);
    float getValMinMot();
    float getValMaxMot();
    float getValBranchementMot();
    float getSeuiCourantChargeInvalide();
    float getSeuilCourantChargeValide();
    float getConsoOrdinateurBord();

    ~Consigne();
};

#endif