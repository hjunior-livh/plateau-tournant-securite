#ifndef C_FORCE_HPP
#define C_FORCE_HPP


class C_Force {

private:
	char adresseCAN;
	float relevePied1;
	float relevePied2;

public:
	
	~C_Force();
	int lire(int nCapteur2);
	C_Force(char adresseCAN = 0x48);
	float getRelevePied1();
	float getRelevePied2();
	

};

#endif 