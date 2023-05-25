#include <iostream>
#include <unistd.h>
#include <math.h>
#include "include/ina219.h"
#include "include/C_courantMoteur.hpp"
#include "include/Cerbere.hpp"
#include "include/Consigne.hpp"

int main() {
    Cerbere* cerbere = new Cerbere();

    cerbere -> verifierCourant();
}