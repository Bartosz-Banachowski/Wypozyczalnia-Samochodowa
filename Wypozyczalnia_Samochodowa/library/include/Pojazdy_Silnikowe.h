#ifndef POJAZDY_SILNIKOWE_H
#define POJAZDY_SILNIKOWE_H

#include <iostream>
#include "Pojazdy.h"

class Pojazdy_Silnikowe : public Pojazdy
{
	private:
        float pojemnosc_silnika;

	public:
        void set_cena_wyliczona() { };
        virtual string toString();
        float get_pojemnosc_silnika() {return pojemnosc_silnika;}
        Pojazdy_Silnikowe(string nazwa_pojazdu, float pojemnosc_silnika);
        virtual ~Pojazdy_Silnikowe();

};

#endif
