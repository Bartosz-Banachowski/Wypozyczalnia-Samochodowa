#ifndef KLIENT_DOMYSLNY_H
#define KLIENT_DOMYSLNY_H

#include <iostream>

#include "Klient_Typ.h"

class Klient_Domyslny : public Klient_Typ
{

	public:
        virtual string get_nazwa_typu_klienta();
        virtual float get_upust();
        virtual int get_max_liczba_pojazdow();
        Klient_Domyslny();
        virtual ~Klient_Domyslny();
};

#endif
