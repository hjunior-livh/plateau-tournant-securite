#include <iostream>
#include <unistd.h>
#include <math.h>

#include "../include/Journal.hpp"


int main()
{
    float intensite;
    Journal* journal = new Journal("~/BDD");

    std::cout << "veuillez entrer une valeure de mesure a journalisé: ";
    std::cin >> intensite;
    std::cout << std::endl;

    journal -> enregistrerIMoteur(intensite);

    std::cout << "veuillez entrer une valeure de mesure qui va etre assimilé a un evenement: ";
    std::cin >> intensite;
    std::cout << std::endl;
    journal -> enregistrerEvenement(Journal::EVENMOTEUR,intensite);
}
