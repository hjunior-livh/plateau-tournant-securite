#ifndef C_CONSIGNE_HPP
#define C_CONSIGNE_HPP


class Consigne {

private:
	float seuilPresence;
    float seuilAbscence;
	float seuilBlocage;

public:
	
    Consigne();
    ~Consigne();
    float obtenirSeuilCourantMoteur();
    float obtenirSeuilsPressence(float& seuilMin ,float& seuilMax);
	float getSeuilmin();
    float getSeuilmax();

};

#endif 