#include <exception>
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

public:
	// PlateauTournant* _unnamed_PlateauTournant_;
	Signalement();

	bool getAlerteMoteur();
	void setAlerteMoteur(bool aAlerteMoteur);

	bool getAlerteBatterie();
	void setAlerteBatterie(bool aAlerteBatterie);

	bool getAlerteFixation();
	void setAlerteFixation(bool aAlerteFixation);

	bool getAlertePresence();
	void setAlertePresence(bool aAlertePresence);

	void signalerProbleme(int code);

	~Signalement();
};

#endif
