#include "cppgpio/output.hpp"
#include <thread>
#include <chrono>

using namespace GPIO; // vert 9, jaune 11, rouge 24
using namespace std;

class Signalisation
{
public:
	Signalisation(int pinVoyantVert, int pinVoyantJaune, int pinVoyantRouge);
	/*bool getOn_off();
	void setOn_off();*/

	void signalerChargeBatterie();
	void finSignalerChargeBatterie();

	void signalerPbAlim();
	void finSignalerPbAlim();
	thread tSignalerPbAlim();

	void signalerPbSecurite();
	void finSignalerPbSecurite();

	void signalerMiseEnMouvement();
	void finirMiseEnMouvement();

	/*void arretUrgence();
	void finArretUrgence();*/

	void allumerVert();
	void allumerJaune();
	void allumerRouge();

	void eteindreVert();
	void eteindreJaune();
	void eteindreRouge();

	bool getChargeEnCours();
	void setChargeEnCours(bool charge);

private:
	bool on_off;
	DigitalOut *voyantVert;
	DigitalOut *voyantJaune;
	DigitalOut *voyantRouge;
	bool clePbAlim;
	bool chargeEnCours;
};