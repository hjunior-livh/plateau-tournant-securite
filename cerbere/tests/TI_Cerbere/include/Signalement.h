#include <exception>
#include <csignal>
using namespace std;

#ifndef SIGNALEMENT_H
#define SIGNALEMENT_H

class Signalement
{
private:
	bool _alerteMoteur;

private:
	bool _alerteBatterie;

private:
	bool _alerteFixation;

private:
	bool _alertePresence;
	bool _alerteSignauxNonconformes;
	bool _alerteOrdreDoubleHoraire;
	bool _alerteOrdreDoubleAntiHoraire;

public:
	static const int SIGNONCONF = 1;
	static const int SIGNONDOUBLEHOR = 2;
	static const int SIGNONDOUBEAR = 3;
	static const int ALERTEMOTEUR = 4;
	static const int ALERTEBATTERIE = 5;
	static const int ALERTEFIXATION = 6;
	static const int ALERTEPRESENCE = 7;

public:
	bool getAlerteMoteur();

public:
	void setAlerteMoteur(bool aAlerteMoteur);

public:
	bool getAlerteBatterie();

public:
	void setAlerteBatterie(bool aAlerteBatterie);

public:
	bool getAlerteFixation();

public:
	void setAlerteFixation(bool aAlerteFixation);

public:
	bool getAlertePresence();

public:
	void setAlertePresence(bool aAlertePresence);

public:
	bool getAlerteSignauxNonconformes();

public:
	bool getAlerteOrdreDoubleHoraire();

public:
	bool getAlerteOrdreDoubleAntiHorairee();
	void setAlerteSignauxNonconformese(bool aalerteSignauxNonconformes);
	void setAlerteOrdreDoubleHoraire(bool alerteOrdreDoubleHoraire);
	void setAlerteOrdreDoubleAntiHorairee(bool aalerteOrdreDoubleAntiHoraire);

public:
	void signalerProbleme(int code);
};

#endif
