#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include <string>
#include <iostream>
#include "Pojazdy_Silnikowe.h"

using namespace std;


class Samochod : public Pojazdy_Silnikowe
{
	private:
        string segment_samochodu;

	public:
        virtual string toString();
        void set_cena_wyliczona();
        Samochod(float pojemnosc_silnika, string segment_samochodu, string nazwa_pojazdu);
        virtual ~Samochod();
        string get_segment() { return segment_samochodu;}

};

#endif
