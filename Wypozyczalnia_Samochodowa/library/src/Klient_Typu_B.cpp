#include "../include/Klient_Typu_B.h"
#include <iostream>

Klient_Typu_B::Klient_Typu_B()
{

}

Klient_Typu_B::~Klient_Typu_B()
{

}

float Klient_Typu_B::get_upust()
{
    if(Klient::get_obrot_klienta() < 1000 && Klient::get_obrot_klienta() > 100) return 50;
    if (Klient::get_obrot_klienta() >= 1000) return 100;
    if (Klient::get_obrot_klienta() <= 100) return 0;

}

int Klient_Typu_B::get_max_liczba_pojazdow()
{
    return 7;
}


string Klient_Typu_B::get_nazwa_typu_klienta()
{
    return "Klient Typu B ";

}
