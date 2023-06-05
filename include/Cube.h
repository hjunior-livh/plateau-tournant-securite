#ifndef __Cube_h__
#define __Cube_h__

#include "PlateauTournant.h"
#include "SignalCube.hpp"
#include "Batterie.h"


class PlateauTournant;
class SignalCube;

class Cube
{
private:
	bool _present;

private:
	bool _fixe;

private:
	PlateauTournant *_lePlateau;

private:
	Batterie *_laBatterie;

private:
	SignalCube *_lesSignaux;

public:
	Cube(PlateauTournant *unPlateau);
	PlateauTournant *getLePlateau();
	Batterie *getLaBatterie();
	SignalCube *getLesSignaux();
	void setLePlateau(PlateauTournant *lui);
	void setLaBatterie(Batterie *elle);
	void setLesSignaux(SignalCube *lui);
	~Cube();
};

/*#include "PlateauTournant.h"
#include "SignalCube.hpp"
#include "Batterie.h"
#ifndef __Cube_h__
#define __Cube_h__

class Cube
{
private:
	bool _present;
	bool _fixe;
	PlateauTournant *_lePlateau;
	SignalCube *_lesSignaux;
	Batterie *_laBatterie;
};*/

#endif
