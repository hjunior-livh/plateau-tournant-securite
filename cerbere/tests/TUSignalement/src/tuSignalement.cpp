#include <iostream>
#include <unistd.h>
#include "../include/Signalement.h"

using namespace std;
    Signalement *leSignalement = new Signalement();

void hand(int sig)
{
    cout << "arret moteur" << endl;
    if (leSignalement->getAlerteFixation()) cout<<"défaut fixation"<<endl;
    else   if (leSignalement->getAlerteMoteur()) cout<<"blocage moteur"<<endl;
    else   if (leSignalement->getAlerteOrdreDoubleAntiHorairee()) cout<<"défaut signaux antihoraire"<<endl;    
    else   if (leSignalement->getAlerteOrdreDoubleHoraire()) cout<<"défaut signaux horaire"<<endl;      
    else   if (leSignalement->getAlertePresence()) cout<<"absence Cube"<<endl;     
    else   if (leSignalement->getAlerteSignauxNonconformes()) cout<<"signaux commande non conformes"<<endl;   
    else   if (leSignalement->getAlerteBatterie()) cout<<"défaut charge batterie"<<endl;           
}

int main()
{
    signal(SIGUSR1, hand);
    int souhait;
    do
    {
        cout << "Quel problème souhaitez-vous signaler ?" << endl;
        cout << "Signaux non conformes (1)" << endl;
        cout << "Double ordre horaire (2)" << endl;
        cout << "Double ordre antihoraire (3)" << endl;
        cout << "Blocage moteur (4)" << endl;
        cout << "Défaut alimentation batterie (5)" << endl;
        cout << "Défaut de fixation (6)" << endl;
        cout << "Absence Cube (7)" << endl;
        cin>>souhait;
        if (1)
            leSignalement->signalerProbleme(Signalement::SIGNONCONF);
        else if (2)
            leSignalement->signalerProbleme(Signalement::SIGNONDOUBLEHOR);
        else if (3)
            leSignalement->signalerProbleme(Signalement::SIGNONDOUBEAR);
        else if (4)
            leSignalement->signalerProbleme(Signalement::ALERTEMOTEUR);
        else if (5)
            leSignalement->signalerProbleme(Signalement::ALERTEBATTERIE);
        else if (6)
            leSignalement->signalerProbleme(Signalement::ALERTEFIXATION);
        else if (7)
            leSignalement->signalerProbleme(Signalement::ALERTEPRESENCE);

        sleep(2);
    } while (true);

    return 0;
}