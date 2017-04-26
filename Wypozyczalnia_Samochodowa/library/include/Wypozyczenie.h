#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <string>
#include <iostream>
#include <sstream>

#include "Pojazdy.h"
#include "Klient.h"
#include <boost/date_time/gregorian/gregorian.hpp>

class Klient;
class Klasa_Aplikacji;
using namespace boost::gregorian;
using namespace std;

class Wypozyczenie
{

	private:
        boost::uuids::random_generator generator;
        boost::uuids::uuid UUID_W;
        date data_poczatkowa;
        date data_koncowa;
        float calkowity_koszt_wypozyczenia;
        float koszt_faktyczny;
        Pojazdy* jaki_pojazd;
        Klient* kto_wypozyczyl;
        Klasa_Aplikacji* rejestr;                                                   //utworzony aby umozliwic przypisanie wypozyczenie do rejestru w chiwli utworzenia obiektu

	public:
        string toString()
        {
            stringstream sout;
            sout<<"UUID Wypozyczenia: "<< Wypozyczenie::getUUID_W() <<endl;
            sout<<"Wypozyczyl: "<<endl;
            sout<<"     UUID Klienta: " << Wypozyczenie::getUUID_K() <<endl;
            sout<<"     Imie Klienta: " << Wypozyczenie::get_imie_k() <<endl;
            sout<<"     Nazwisko Klienta: " << Wypozyczenie::get_nazwisko_k() <<endl;
            sout<<"Pojazd: "<<endl;
            sout<<"     UUID Pojazdu: " << Wypozyczenie::getUUID_P()<<endl;
            sout<<"     Nazwa Pojazdu: " << Wypozyczenie::get_nazwa_p()<<endl;
            sout<<"Data Poczatkowa: " << Wypozyczenie::get_data_poczatkowa() <<endl;
            sout<<"Data Koncowa "<< Wypozyczenie::get_data_koncowa()<<endl;
            sout<<"Ilosc dni wypozyczenia: "<< Wypozyczenie::get_liczba_dni_wyp()<<endl;
            sout<<"Calkowity koszt wypozyczenia: "<<Wypozyczenie::get_calkowity_koszt_wypozyczenia()<<endl;

            return sout.str();

        }

        string toStringg()
        {
             stringstream sout;
            sout<<"UUID Wypozyczenia: "<< Wypozyczenie::getUUID_W() <<endl;
            sout<<"Imie Klienta: "<< Wypozyczenie::get_imie_k() <<endl;
            sout<<"Nazwisko Klienta: "<< Wypozyczenie::get_nazwisko_k() <<endl;
            sout<<"UUID Klienta: "<< Wypozyczenie::getUUID_K() <<endl;
            sout<<"Nazwa Samochodu: " << Wypozyczenie::get_nazwa_p()<<endl;
            sout<<"UUID Pojazdu: "<< Wypozyczenie::getUUID_P() <<endl;
            sout<<"Data Poczatkowa: " << Wypozyczenie::get_data_poczatkowa() <<endl;
            sout<<"Liczba biezacych wypozyczen: " << Wypozyczenie::get_liczba_wyp_a() <<endl;

            return sout.str();
        }


        void set_calkowity_koszt_wypozyczenia() { this->calkowity_koszt_wypozyczenia = get_liczba_dni_wyp()*get_koszt_faktyczny(); }
        void setUUID_W() {this->UUID_W = generator();}
        void set_data_koncowa( date d) { this->data_koncowa = d; }
        float get_koszt_faktyczny() {return koszt_faktyczny;}
        date get_data_poczatkowa() {return data_poczatkowa; }
        date get_data_koncowa() {return data_koncowa; }
        float get_calkowity_koszt_wypozyczenia() { return calkowity_koszt_wypozyczenia; }
        boost::uuids::uuid getUUID_W() { return UUID_W; };
        float get_liczba_dni_wyp() {return (data_koncowa-data_poczatkowa).days();}
        Pojazdy* get_jaki_pojazd() {return jaki_pojazd; }
        Klient* get_kto_wypozyczyl() {return kto_wypozyczyl;}
        int get_liczba_wyp_a();
        void set_liczba_wyp_a();
        void set_koszt_faktyczny();
        void set_Obrot(float ile);
        string get_nazwisko_k();
        boost::uuids::uuid getUUID_K();
        string get_nazwa_p();
        boost::uuids::uuid getUUID_P();
        string get_imie_k();

        Wypozyczenie(Klient* kto_wypozyczyl, Pojazdy* jaki_pojazd, date data_poczatkowa, Klasa_Aplikacji* rejestr );
        ~Wypozyczenie();


};

#endif
