#include "../include/Cube.h"
#include "../include/PlateauTournant.h"

Cube::Cube(PlateauTournant *unPlateau)
{
    this->_laBatterie = new Batterie();
        unsigned int signal1 = 5;   
    unsigned int signal2 = 6;  
    this->_lesSignaux = new SignalCube(unPlateau, signal1, signal2, GPIO_PULL::OFF);
    this->_fixe = true;
    this->_present = true;
}
PlateauTournant *Cube::getLePlateau()
{
    return _lePlateau;
}
Batterie *Cube::getLaBatterie()
{
    return _laBatterie;
}
SignalCube *Cube::getLesSignaux()
{
    return _lesSignaux;
}
void Cube::setLePlateau(PlateauTournant *lui)
{
    this->_lePlateau = lui;
}
void Cube::setLaBatterie(Batterie *elle)
{
    this->_laBatterie = elle;
}
void Cube::setLesSignaux(SignalCube *lui)
{
    this->_lesSignaux = lui;
}
Cube::~Cube()
{
    delete this->_laBatterie;
    delete this->_lesSignaux;
}
