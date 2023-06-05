#include <exception>
using namespace std;

#include "../include/Position.h"

void Position::triggered(unsigned int aGpio) {
	throw "Not yet implemented";
}

void Position::setCapteur1(DigitalIn aCapteur1) {
	this->_capteur1 = aCapteur1;
}

DigitalIn Position::getCapteur1() {
	return this->_capteur1;
}

