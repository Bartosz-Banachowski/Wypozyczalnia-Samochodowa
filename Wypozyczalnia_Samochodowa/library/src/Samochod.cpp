#include "../include/Samochod.h"
#include <iostream>

Samochod::Samochod(float pojemnosc_silnika, string segment_samochodu, string nazwa_samochodu)
                   : Pojazdy_Silnikowe(nazwa_samochodu, pojemnosc_silnika),
                   segment_samochodu(segment_samochodu)
{

}

Samochod::~Samochod()
{

}


void Samochod::set_cena_wyliczona()
{
    float mnoznik;
    if(segment_samochodu == "A" || segment_samochodu == "a") { mnoznik = 1.0; }
    if(segment_samochodu == "B" || segment_samochodu == "b") { mnoznik = 1.1; }
    if(segment_samochodu == "C" || segment_samochodu == "c") { mnoznik = 1.2; }
    if(segment_samochodu == "D" || segment_samochodu == "d") { mnoznik = 1.3; }
    if(segment_samochodu == "E" || segment_samochodu == "e") { mnoznik = 1.5; }

     if(Pojazdy_Silnikowe::get_pojemnosc_silnika() <1000)
        {
            this->cena_wyliczona = (1.0)*mnoznik*Pojazdy::get_cena_bazowa();

        }
    else if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1000 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 2000 )
        {
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1000 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1250) { this->cena_wyliczona = 1.1*mnoznik*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1250 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1500) { this->cena_wyliczona = 1.2*mnoznik*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1500 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 1750) { this->cena_wyliczona = 1.3*mnoznik*Pojazdy::get_cena_bazowa(); }
            if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 1750 && Pojazdy_Silnikowe::get_pojemnosc_silnika() < 2000) { this->cena_wyliczona = 1.4*mnoznik*Pojazdy::get_cena_bazowa(); }
        }
    else if ( Pojazdy_Silnikowe::get_pojemnosc_silnika() >= 2000 )
            this->cena_wyliczona = 1.5*mnoznik*Pojazdy::get_cena_bazowa();


}


string Samochod::toString()
{
    stringstream sout;
    sout << Pojazdy_Silnikowe::toString();
    sout << "Segment Samochodu: " << get_segment() <<endl;


    return sout.str();
}
