#include "../include/Pojazdy.h"
#include <iostream>

Pojazdy::Pojazdy(string nazwa_pojazdu) : nazwa_pojazdu(nazwa_pojazdu)
{
    setUUID();
}

Pojazdy::~Pojazdy()
{

}

string Pojazdy::toString()
{
    stringstream sout;
    sout << "UUID Pojazdu: " << getUUID() <<endl;
    sout << "Nazwa Pojazdu: " << get_nazwa_pojazdu() <<endl;
    sout << "Cena Bazowa: " << get_cena_bazowa() <<endl;
    sout << "Cena wyliczona: " << get_cena_wyliczona() <<endl;

    return sout.str();
}
