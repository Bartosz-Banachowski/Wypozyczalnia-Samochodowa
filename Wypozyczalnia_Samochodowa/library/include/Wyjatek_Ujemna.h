#ifndef WYJATEK_UJEMNA_H
#define WYJATEK_UJEMNA_H

#include <string>
#include <iostream>

class Pojazdy;
using std::string;
using std::stringstream;
using std::endl;

class Wyjatek_Ujemna
{

    private:
        Pojazdy* Ujemna;
        float ujemny_argument;  //przekaza wartosc ujemnego argumentu przy lapaniu wyjatku

    public:
        void opis();
        Wyjatek_Ujemna(Pojazdy* Ujemna, float ujemny_argument) :Ujemna(Ujemna),
                                                                ujemny_argument(ujemny_argument) {}
        virtual ~Wyjatek_Ujemna() {}

};

#endif // WYJATEK_UJEMNA_H
