#ifndef MOTOROWER_H
#define MOTOROWER_H

#include <string>
#include <iostream>
#include "Pojazdy_Silnikowe.h"

using namespace std;


class Motorower :public Pojazdy_Silnikowe
{

	public:
        virtual string toString();
        void set_cena_wyliczona();
        Motorower(float pojemnosc_silnika, string nazwa_pojazdu);
        virtual ~Motorower();

};

#endif
