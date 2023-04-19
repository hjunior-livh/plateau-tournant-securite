#ifndef CONSIGNE_HPP
#define CONSIGNE_HPP


class Consigne
{

private:
    Consigne* consigne;
    int ValMinMot;
    int ValMaxMot;
public:
    Consigne();
    void setValMinMot(int val);
    void setValMaxMot(int val);
    int getValMinMot();
    int getValMaxMot();
    ~Consigne();
};

#endif // CONSIGNE_HPP