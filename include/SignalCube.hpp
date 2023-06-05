#include <exception>
using namespace std;
#ifndef __SignalCube_h__
#define __SignalCube_h__

#include <unistd.h>    // Inclure la bibliothèque pour la fonction sleep
#include "cppgpio.hpp" // Inclure la bibliothèque C++ pour les GPIO
#include "PlateauTournant.h"

using namespace GPIO;

class PlateauTournant;

class SignalCube : public InputDetect
{
private:
    DigitalIn signal1;
    DigitalIn signal2;
    PlateauTournant *_plateauTournant;
    bool conforme = true;
    short anomalie;
    short seuil = 3;

public:
    SignalCube( /// GPIO pin to use
        PlateauTournant *_plateauTournant,
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
        : InputDetect({pin1, pin2}, GPIO_EDGE::BOTH), signal1(pin1, pullupdown, min_trigger_interval, min_hold_interval),
          signal2(pin2, pullupdown, min_trigger_interval, min_hold_interval )
    {
        this->_plateauTournant = _plateauTournant;
    }

    virtual void triggered(unsigned int gpio);

    ~SignalCube(void);

private:
    void decoder_ordre();

public:
    void setSignal1(DigitalIn aSignal1);

public:
    DigitalIn getSignal1();

public:
    void setSignal2(DigitalIn aSignal2);

public:
    DigitalIn getSignal2();

public:
    void setPlateauTournant(PlateauTournant *plateauTournant);

public:
    PlateauTournant *getPlateauTournant();
};

#endif
