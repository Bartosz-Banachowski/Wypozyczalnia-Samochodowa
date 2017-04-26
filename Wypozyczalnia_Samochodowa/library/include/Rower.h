#ifndef ROWER_H
#define ROWER_H

#include <string>
#include <iostream>
#include "Pojazdy.h"


using namespace std;


class Rower : public Pojazdy
{
	public:
        void set_cena_wyliczona();
        virtual string toString();
        Rower(string nazwa_pojazdu);
        virtual ~Rower();

};

#endif
