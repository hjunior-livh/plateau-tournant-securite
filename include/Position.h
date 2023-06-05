#include <exception>
using namespace std;

#ifndef __Position_h__
#define __Position_h__

#include "cppgpio/buttons.hpp"
using namespace GPIO;

class Position : public InputDetect
{
private:
	DigitalIn _capteur1;

private:
	DigitalIn _capteur2;

public:
	 virtual void triggered(unsigned int aGpio);

public:
	void setCapteur1(DigitalIn aCapteur1);

public:
	DigitalIn getCapteur1();
	Position( /// GPIO pin to use
		unsigned int pin1,
		unsigned int pin2,

		/// pullup / down / none
		GPIO_PULL pullupdown = GPIO_PULL::OFF,

		/// define the interval that has to pass between two events
		std::chrono::nanoseconds min_trigger_interval = std::chrono::nanoseconds(2 * 1000 * 1000), // 2 ms

		/// define the minimum time the gpio pin has to be triggered
		/// before a trigger is detected (to protect against noise on
		/// the line)
		std::chrono::nanoseconds min_hold_interval = std::chrono::nanoseconds(1 * 1000 * 1000)) // 1 ms
		: InputDetect({pin1, pin2}, GPIO_EDGE::BOTH), _capteur1(pin1, pullupdown, min_trigger_interval, min_hold_interval),
		  _capteur2(pin2, pullupdown, min_trigger_interval, min_hold_interval){};
};

#endif
