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
    void setValMinMot(float val);
    void setValMaxMot(float val);
    float getValMinMot();
    float getValMaxMot();
    float getValBranchementMot();

    //Ce qui est demandé par le chef de projet
    void obtenirSeuillCourantMoteur(float &seuilBlocageMin, float &seuilBlocageAlerte, float &seuilBlocageBranchement);
    float obtenirSeuillPrésenceMoteur(float &seuilPresenceCubeMin, float &seuilPresenceCubeMax);
    ~Consigne();
};

#endif // CONSIGNE_HPP