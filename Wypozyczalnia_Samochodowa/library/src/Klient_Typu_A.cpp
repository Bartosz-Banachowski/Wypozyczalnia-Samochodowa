#include "../include/Klient_Typu_A.h"
#include "Klasa_Zaslepkowa.h"

#include <iostream>

Klient_Typu_A::Klient_Typu_A()
{

}

Klient_Typu_A::~Klient_Typu_A()
{

}

float Klient_Typu_A::get_upust()
{
    return ((5/100)*Klient::get_obrot_klienta());
}

int Klient_Typu_A::get_max_liczba_pojazdow()
{

    return 5;
}

string Klient_Typu_A::get_nazwa_typu_klienta()
{
    return "Klient Typu A ";

}
