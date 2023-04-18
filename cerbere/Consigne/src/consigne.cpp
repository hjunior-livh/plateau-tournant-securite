

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <unistd.h>

#include "../include/consigne.hpp"




Consigne::~Consigne()
{

}
Consigne::Consigne()
{
 seuilPresence = 2800;
 seuilAbscence = 10000; 


}
float Consigne::obtenirSeuilCourantMoteur()
{
    
}
float Consigne::obtenirSeuilsPressence(float& seuilMin ,float& seuilMax)
{
    
}
float Consigne::getSeuilmin()
{
    return seuilPresence;
}
float Consigne::getSeuilmax()
{
    return seuilAbscence;
}