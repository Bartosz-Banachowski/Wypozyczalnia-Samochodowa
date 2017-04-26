#include "../include/Klient.h"
#include "Klient_Typ.h"
#include "Klasa_Aplikacji.h"

Klient::Klient() {}

Klient::Klient(string i, string n, string a, string nr_dow, float ob, Klient_Typ* typ_k)
              : imie(i),
                nazwisko(n),
                adres(a),
                nr_dowodu_osobistego(nr_dow),
                obrot_klienta(ob),
                typ_klienta(typ_k)

{
    Klient::setUUID();

}

Klient::~Klient()
{

}


string Klient::toString()                                           //pelny opis klienta uzywany w listie klientow
{
     stringstream sout;
    sout<<"UUID: "<<Klient::getUUID()<<endl;
    sout<<"Imie: "<< Klient::get_imie()<<endl;
    sout<<"Nazwisko: "<< Klient::get_nazwisko()<<endl;
    sout<<"Adres: "<< Klient::get_adres()<<endl;
    sout<<"Nr dowodu osobistego: "<< Klient::get_nr_dowodu_osobistego()<<endl;
    sout<<"Obrot klienta: "<< Klient::get_obrot_klienta()<<endl;
    sout<<"Typ klienta: "<<Klient::get_nazwa_typu()<<endl;
    sout<<"Upust: "<< Klient::get_ile_upustu()<<endl;
    sout<<"Max liczba wypozyczen: "<< Klient::get_max_wypozyczen()<<endl;

    return sout.str();

}


string Klient::get_nazwa_typu() { return typ_klienta->get_nazwa_typu_klienta();}        //metody dostepowe do typu klienta
float Klient::get_ile_upustu() { return typ_klienta->get_upust(); }
int Klient::get_max_wypozyczen() { return typ_klienta->get_max_liczba_pojazdow(); }
