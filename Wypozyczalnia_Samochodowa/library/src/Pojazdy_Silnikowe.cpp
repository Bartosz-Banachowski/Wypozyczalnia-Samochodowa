#include "../include/Pojazdy_Silnikowe.h"
#include <iostream>

Pojazdy_Silnikowe::Pojazdy_Silnikowe( string nazwa_pojazdu, float pojemnosc_silnika)
                                     :Pojazdy(nazwa_pojazdu),
                                     pojemnosc_silnika(pojemnosc_silnika)
{

}

Pojazdy_Silnikowe::~Pojazdy_Silnikowe()
{

}

string Pojazdy_Silnikowe::toString()
{
    stringstream sout;
    sout << Pojazdy::toString();
    sout << "Pojemnosc Silnika " << get_pojemnosc_silnika() <<endl;


    return sout.str();
}
