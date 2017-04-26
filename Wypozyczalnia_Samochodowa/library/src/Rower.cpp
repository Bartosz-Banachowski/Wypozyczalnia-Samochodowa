#include "../include/Rower.h"
#include <iostream>

Rower::Rower(string nazwa_pojazdu) : Pojazdy(nazwa_pojazdu)
{
    Pojazdy::setUUID();

}

Rower::~Rower()
{

}

void Rower::set_cena_wyliczona()
{

    this->cena_wyliczona = Pojazdy::get_cena_bazowa();
}

string Rower::toString()
{
    stringstream sout;
    sout << Pojazdy::toString() <<endl;

    return sout.str();
}
