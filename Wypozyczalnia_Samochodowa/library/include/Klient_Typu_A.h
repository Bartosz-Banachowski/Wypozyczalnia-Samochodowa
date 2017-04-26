#ifndef KLIENT_TYPU_A_H
#define KLIENT_TYPU_A_H

#include <string>
#include "Klient_Typ.h"


class Klient_Typu_A : public Klient_Typ
{


	public:

        virtual string get_nazwa_typu_klienta();
        virtual float get_upust();
        virtual int get_max_liczba_pojazdow ();
        Klient_Typu_A();
        virtual ~Klient_Typu_A();
};

#endif
