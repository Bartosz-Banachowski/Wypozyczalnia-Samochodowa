#ifndef POJAZDY_H
#define POJAZDY_H

#include <string>
#include <sstream>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "Wyjatek_Ujemna.h"

using namespace std;

class Pojazdy
{
	private:
        boost::uuids::random_generator generator;
        boost::uuids::uuid UUID_P;
        float cena_bazowa;                          //cena od ktorej wyliczana jest cena_wyliczona na podstawia schematu- pojemnosc silnika i klasy
        string nazwa_pojazdu;

    protected:
        float cena_wyliczona;                       //cena wypozyczenia pojazdu bez upustu


	public:
        void setUUID() {this->UUID_P = generator();}
        virtual string toString();
        void set_cena_bazowa(float cena_bazowa) { if (cena_bazowa < 0 ) {throw Wyjatek_Ujemna(this,cena_bazowa); } this->cena_bazowa = cena_bazowa;}
        virtual void set_cena_wyliczona () { };
        boost::uuids::uuid getUUID() { return UUID_P;};
        string get_nazwa_pojazdu() {return nazwa_pojazdu;}
        float get_cena_bazowa() {return cena_bazowa; }
        float get_cena_wyliczona() {return cena_wyliczona;}
        Pojazdy() {}
        Pojazdy(string nazwa_pojazdu);
        virtual ~Pojazdy();
};

#endif
