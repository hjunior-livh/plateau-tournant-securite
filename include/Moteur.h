
#ifndef __Moteur_h__
#define __Moteur_h__

#include "cppgpio/output.hpp"
#include <unistd.h>

using namespace GPIO;

class Moteur{
    public:
      /// @brief Constructeur du moteur
      /// @param pinPWM broche sur laquelle est branchée l'entrée PWM du module pont en H
      /// @param pinSensMoteur broche sur laquelle est branchée l'entrée Direction du module pont en H
      /// @param periode période souhaitée pour la PWM en dixième de ms
      Moteur(unsigned int pinPWM=16, unsigned int pinSensMoteur=17, unsigned int periode = 7);
      ~Moteur();
      /// @brief lancement de la rotation horaire du moteur à une vitesse déterminée par le rapport cyclique
      /// @param rapportCyclique en %
      void tournerHoraire(unsigned int rapportCyclique); 
      /// @brief lancement de la rotation antihoraire du moteur à une vitesse déterminée par le rapport cyclique
      /// @param rapportCyclique en %      
      void tournerAntiHoraire(unsigned int rapportCyclique); 
      void arretMoteur(); //eteint phase et enable
      void modifierSensMoteur(bool etat); //modifie l'état de phase
      void modifierValRapportCyclique(unsigned int rapportCyclique); //modifie la valeur du ratio du PWM
      bool getEstEnMouvement(); //getter de l'attribut estEnMouvement
      void setEstEnMouvement(bool etat); //setter setEstEnMouvement, pas vraiment utile
      int getRatio(); //getter de l'attribut ratio, pas vraiment utile
      void setRatio(unsigned int rapportCyclique); //setter de l'attribut ratio, pas vraiment utile
    
    private:
        bool estEnMouvement;
        DigitalOut* objPhase;
        PWMOut* objEnablePWM;
        unsigned int periode;
        unsigned int ratio;
};


#endif
