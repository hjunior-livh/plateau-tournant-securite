#include <exception>
#include <csignal>
using namespace std;

#ifndef __Signalement_h__
#define __Signalement_h__

class Signalement
{
private:
	bool _alerteMoteur;
	bool _alerteBatterie;
	bool _alerteFixation;
	bool _alertePresence;
	bool _alerteSignauxNonconformes;
	bool _alerteOrdreDoubleHoraire;
	bool _alerteOrdreDoubleAntiHoraire;
	bool _alerterForcer;
	bool _alerterConnexionMoteur;		

public:
	static const int SIGNONCONF = 1;
	static const int SIGNONDOUBLEHOR = 2;
	static const int SIGNONDOUBEAR = 3;
	static const int ALERTEMOTEUR = 4;
	static const int ALERTEBATTERIE = 5;
	static const int ALERTEFIXATION = 6;
	static const int ALERTEPRESENCE = 7;
	static const int ALERTEFORCER = 8;	
	static const int CONNEXIONMOTEUR = 9;
public:
	~Signalement();

	Signalement();

	bool getAlerteMoteur();

	void setAlerteMoteur(bool aAlerteMoteur);

	bool getAlerteBatterie();

	void setAlerteBatterie(bool aAlerteBatterie);

	bool getAlerteFixation();

	void setAlerteFixation(bool aAlerteFixation);

	bool getAlertePresence();

	void setAlertePresence(bool aAlertePresence);

	bool getAlerteForcer();

	void setAlerteForcer(bool aAlerteForcer);	

public:
	bool getAlerteSignauxNonconformes();

public:
	bool getAlerteOrdreDoubleHoraire();

public:
	bool getAlerteOrdreDoubleAntiHorairee();
	void setAlerteSignauxNonconformese(bool aalerteSignauxNonconformes);
	void setAlerteOrdreDoubleHoraire(bool alerteOrdreDoubleHoraire);
	void setAlerteOrdreDoubleAntiHorairee(bool aalerteOrdreDoubleAntiHoraire);
	void setAlerterConnexionMoteur(bool alerterConnexionMoteur);
	bool getAlerterConnexionMoteur();	

public:
	void signalerProbleme(int code);
};

#endif
