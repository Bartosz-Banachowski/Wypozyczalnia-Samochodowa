#include "../include/Motorower.h"
#include <iostream>

Motorower::Motorower(float pojemnosc_silnika, string nazwa_pojazdu)
                    : Pojazdy_Silnikowe(nazwa_pojazdu, pojemnosc_silnika)
{

}

Motorower::~Motorower()
{

}

void Motorower::set_cena_wyliczona()
{

    if(Pojazdy_Silnikowe::get_pojemnosc_silnika() <1000)
        {
            this->cena_wyliczona = (1.0)*Pojazdy::get_cena_bazowa();

        }
    else if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1000 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 2000 )
        {
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1000 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1250) { this->cena_wyliczona = 1.1*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1250 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1500) { this->cena_wyliczona = 1.2*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1500 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1750) { this->cena_wyliczona = 1.3*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1750 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 2000) { this->cena_wyliczona = 1.4*Pojazdy::get_cena_bazowa(); }
        }
    else if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 2000 )
            this->cena_wyliczona = 1.5*Pojazdy::get_cena_bazowa();

}

string Motorower::toString()
{
    stringstream sout;
    sout << Pojazdy_Silnikowe::toString() <<endl;

    return sout.str();
}
