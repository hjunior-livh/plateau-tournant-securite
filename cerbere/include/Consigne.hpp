#ifndef CONSIGNE_HPP
#define CONSIGNE_HPP


class Consigne
{

private:
    float seuilPresenceCubeMin;
    float seuilPresenceCubeMax;
    float seuilBlocageMin;
    float seuilBlocageAlerte;
    float seuilBlocageBranchement;
public:
    Consigne();
    //j'avais ca qui avait l'air simple mais bon non.
    void setValMinMot(int val);
    void setValMaxMot(int val);
    int getValMinMot();
    int getValMaxMot();

    //Ce qui est demandé par le chef de projet
    float obtenirSeuillCourantMoteur(float &seuilBlocageMin, float &seuilBlocageAlerte, float &seuilBlocageBranchement);
    float obtenirSeuillPrésenceMoteur(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax);
    ~Consigne();
};

#endif // CONSIGNE_HPP