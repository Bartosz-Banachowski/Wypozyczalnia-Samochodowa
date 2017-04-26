#ifndef KLIENT_TYP_H
#define KLIENT_TYP_H

#include <iostream>
#include "Klient.h"

using namespace std;

class Klient_Typ :public Klient
{

        public:
            virtual string get_nazwa_typu_klienta()=0;
            virtual float get_upust()=0;
            virtual int get_max_liczba_pojazdow()=0;
            Klient_Typ() {};
            virtual ~Klient_Typ(){};
};

#endif
