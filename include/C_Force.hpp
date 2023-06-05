#include <exception>
using namespace std;

#ifndef __C_Force_h__
#define __C_Force_h__

#include "cppgpio/i2c.hpp"

class C_Force
{

private:
	char adresseCAN;
	float tensionAlimentation;
	float resistanceProtection;
	float relevePied1;
	float relevePied2;

public:
	~C_Force();
	int lire(int nCapteur2);
	C_Force(char adresseCAN = 0x48, float tensionAlimentation = 5, float resistanceProtection = 21000);
	float getRelevePied1();
	float getRelevePied2();
	void setTensionAlimentation(float tensionAlimentation);
	void setResistanceProtection(float resistanceProtection);
};

#endif
