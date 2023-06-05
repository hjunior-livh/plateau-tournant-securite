#include "../include/Moteur.h"


using namespace GPIO;


Moteur::Moteur(unsigned int pinPWM, unsigned int pinSensMoteur, unsigned int periode){ //unsigned short int est codé sur 2 octets, enable et phase sont le numéro des pins utilisées

    this->objPhase = new DigitalOut(pinSensMoteur); //objet permettant de changer le sens de rotation du moteur, prend en argument la pin
    this->objEnablePWM = new PWMOut(pinPWM); //objet permettant de contrôller le PWM moteur, prend en argument la pin
    if ((periode<1024) && (periode>0)) 
    {
        this->periode = periode -2;
    }
    else {
        this->periode = 5;
    }
    this->objEnablePWM->set_range(periode); //range = rapport de division à partir duquel la période est calculée
    this->ratio = 0; //attribut ratio
}

Moteur::~Moteur(){
    delete this->objPhase;
    delete this->objEnablePWM;
}

void Moteur::tournerHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans un sens avec le paramètre rapportCyclique
    this->ratio = (rapportCyclique* this->periode)/100 ;
    this->objEnablePWM->set_range(this->periode);
    if(this->estEnMouvement == true){ //si le plateau est déja en mouvement (probleme)
        this->objEnablePWM->set_ratio(0);
        this->estEnMouvement = true;
        usleep(100000); //attendre 0.1s
    }
    this->estEnMouvement = true; //le plateau est en mouvement
    this->objPhase->on(); //allumer phase (sens rotation)
    for(unsigned int valRatio = 1; valRatio <= this->ratio; valRatio++){ //augmentation progressive de la vitesse moteur (augmentation progressive PWM)
        this->objEnablePWM->set_ratio(valRatio);
        usleep(10000); //augmentation du PWM toutes les 10ms, 10*valRatioms d'augmentation de la PWM au total
    }
}

void Moteur::tournerAntiHoraire(unsigned int rapportCyclique){ //fais tourner le moteur dans l'autre sens avec l'attribut ratio
    this->ratio = (rapportCyclique* this->periode)/100 ;
    this->objEnablePWM->set_range(this->periode);
    if(this->estEnMouvement == true){ //si le plateau est déja en mouvement (probleme)
        this->objEnablePWM->set_ratio(0);
        this->estEnMouvement = false;
        usleep(100000); //attendre 0.1s
    }
    this->estEnMouvement = true; //le plateau est en mouvement
    this->objPhase->off(); //eteindre phase (sens rotation)
    for(unsigned int valRatio = 1; valRatio <= this->ratio; valRatio++){ //augmentation progressive de la vitesse moteur (augmentation progressive PWM)
        this->objEnablePWM->set_ratio(valRatio);
        usleep(10000); //augmentation du PWM toutes les 10ms, 10*valRatioms d'augmentation de la PWM au total
    }
}

void Moteur::arretMoteur(){ //eteint phase et enable
    this->estEnMouvement = false;
    this->objEnablePWM->set_ratio(0); //objet objEnablePWM éteint, ratio 0
    this->objEnablePWM->set_range(0); //objet objEnablePWM éteint, range 0
    this->objPhase->off(); //objet objPhase éteint
}

void Moteur::modifierSensMoteur(bool etat){ //modifie l'état de phase
    etat ? this->objPhase->on() : this->objPhase->off();
}

void Moteur::modifierValRapportCyclique(unsigned int rapportCyclique){ //modifie la valeur du ratio du PWM, voir si le traitement pour estEnMouvement est à faire ici ?
    this->ratio = rapportCyclique;
    this->objEnablePWM->set_ratio(rapportCyclique);
    if(rapportCyclique != 0){ //si le PWM n'est pas nul
        this->estEnMouvement = true;
    }
    else{ //si le PWM est nul
        this->estEnMouvement = false;
    }
}

bool Moteur::getEstEnMouvement(){ //getter de l'attribut estEnMouvement
    return this->estEnMouvement;
}

void Moteur::setEstEnMouvement(bool etat){ //setter setEstEnMouvement, pas vraiment utile
    this->estEnMouvement = etat;
}

int Moteur::getRatio(){ //getter de l'attribut ratio, pas vraiment utile
    return this->ratio;
}

void Moteur::setRatio(unsigned int rapportCyclique){ //setter de l'attribut ratio, pas vraiment utile
    this->ratio = ratio;
}