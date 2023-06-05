#include <exception>
using namespace std;

#include "../include/Ares.h"
#include <unistd.h>

Ares::Ares(Signalement *aSignalement, Consigne *aConsigne, Journal *aJournal)
{
    _lAlimentationB = new AlimentationBatterie(23, 0x44);
    this->_laConsigne = aConsigne;
    this->_laPosition = new Position(22, 25);
    this->_laSauvegarde = new Sauvegarde();
    this->_laSignalisation = new Signalisation(9, 11, 24);
    this->_leJournal = aJournal;
    this->_lePilote = new Moteur(16, 17, 7);
    this->_leSignalement = aSignalement;
    this->_leSonore = new HautParleur();
}

void Ares::alerteChargeOn()
{
    _leSignalement->setAlerteBatterie(true);
}

void Ares::alerteChargeOff()
{
    _leSignalement->setAlerteBatterie(false);
}
void Ares::immobiliser()
{
    _lePilote->arretMoteur();
    _laSignalisation->finirMiseEnMouvement();
    thread chargeBatterie = tAlimenterBatterie();
    chargeBatterie.detach();
}
void Ares::tournerAntiHoraire()
{
    _laSignalisation->signalerMiseEnMouvement();
    _lePilote->tournerAntiHoraire(100);
}
void Ares::tournerHoraire()
{
    _laSignalisation->signalerMiseEnMouvement();
    _lePilote->tournerHoraire(100);
}
void Ares::alimenterBatterie()
{
    float iCourant;
    float tension;
    float seuiCourantChargeInvalide;
    float seuilCourantChargeValide;
    usleep(2000000);
    seuiCourantChargeInvalide = _laConsigne->getSeuiCourantChargeInvalide();
    seuilCourantChargeValide = _laConsigne->getSeuilCourantChargeValide();
    _lAlimentationB->alimenter();
    _lAlimentationB->releverDonneesCharge();
    _lAlimentationB->obtenirDonnees();
    iCourant = _lAlimentationB->getCourant();
    tension = _lAlimentationB->getTension();
    if (iCourant > _laConsigne->getConsoOrdinateurBord() + 0.2)
    {
        seuilCourantChargeValide = seuilCourantChargeValide + _laConsigne->getConsoOrdinateurBord();
    }
    else if ((iCourant < seuiCourantChargeInvalide) && !_leSignalement->getAlerteBatterie())
    {
        _leJournal->enregistrerEvenement(Journal::EVENBATTERIE, iCourant);
        this->alerteChargeOn();
        _lAlimentationB->couper();
        _leSignalement->signalerProbleme(Signalement::ALERTEBATTERIE);
    }
    if ((iCourant > seuilCourantChargeValide) && _leSignalement->getAlerteBatterie())
    {
        _leJournal->enregistrerFinEvenement(Signalement::ALERTEBATTERIE);
        _leSignalement->setAlerteBatterie(false);
    }
    else
    {
        this->_laSignalisation->signalerChargeBatterie();
        while (iCourant > seuilCourantChargeValide)
        {
            this->alerteChargeOff();
            _lAlimentationB->releverDonneesCharge();
            _lAlimentationB->obtenirDonnees();
            iCourant = _lAlimentationB->getCourant();
            tension = _lAlimentationB->getTension();
            _leJournal->enregistrerDonneesBatterie(iCourant,tension);
            std::this_thread::sleep_for(std::chrono::minutes(5));
        }
    }
    _lAlimentationB->couper();
    _laSignalisation->finSignalerChargeBatterie();
}
thread Ares::tAlimenterBatterie()
{
    return thread([this]
                  { alimenterBatterie(); });
}
Ares::~Ares()
{
    delete this->_laPosition ;
    delete this->_laSauvegarde;
    delete this->_laSignalisation;
    delete this->_lePilote;
    delete this->_leSonore;
}

void Ares::commuterAlimentation()
{
    _lAlimentationB->alimenter();
}

void Ares::mesurerCourantCharge()
{
    _lAlimentationB->releverDonneesCharge();
    _lAlimentationB->obtenirDonnees();
}
