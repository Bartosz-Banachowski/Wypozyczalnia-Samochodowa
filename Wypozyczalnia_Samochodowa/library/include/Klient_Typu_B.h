#ifndef KLIENT_TYPU_B_H
#define KLIENT_TYPU_B_H

#include <iostream>
#include <cmath>
#include "Klient_Typ.h"

class Klient_Typu_B : public Klient_Typ
{

	public:
        virtual string get_nazwa_typu_klienta();
        virtual float get_upust();
        virtual int get_max_liczba_pojazdow();
        Klient_Typu_B();
        virtual ~Klient_Typu_B();
};

#endif
