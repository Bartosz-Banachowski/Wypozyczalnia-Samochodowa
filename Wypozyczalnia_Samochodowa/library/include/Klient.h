#ifndef KLIENT_H
#define KLIENT_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>


#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "Klient.h"
#include "Wypozyczenie.h"
//#include "Klasa_Aplikacji.h"

class Klient_Typ;
class Wypozyczenie;
class Klasa_Aplikacji;

using namespace std;

class Klient
{
	private:
        boost::uuids::random_generator generator;
        boost::uuids::uuid UUID_K;
        string imie;
        string nazwisko;
        string adres;
        string nr_dowodu_osobistego;
        float obrot_klienta;
        Klient_Typ* typ_klienta;                        // zmienna przechowujaca aktualny typ klienta
        int liczba_wyp_aktualnych=0;                       // liczba juz wypozyczonych aut

	public:
       // friend class Klasa_Zaslepkowa;
        void inkr_wyp_aktualnych() { this->liczba_wyp_aktualnych++; }
        void dekr_wyp_aktualnych() { if (this->liczba_wyp_aktualnych >= 1)this->liczba_wyp_aktualnych--; else this->liczba_wyp_aktualnych == 0; }
        void setUUID() {this->UUID_K = generator();}

        string toString();
        void uaktualnij_obrot_klienta(float uaktualnij_o) {this->obrot_klienta = this->obrot_klienta + uaktualnij_o; }

        int get_liczba_wyp_aktualnych() { return liczba_wyp_aktualnych; }
        string get_nazwa_typu();
        float get_ile_upustu();
        int get_max_wypozyczen();
        boost::uuids::uuid getUUID() { return UUID_K; };
        string get_imie() {return imie;}            const
        string get_nazwisko() {return nazwisko;}    const
        string get_adres() {return adres;}          const
        string get_nr_dowodu_osobistego() {return nr_dowodu_osobistego;} const
        float get_obrot_klienta() {return obrot_klienta; }

        Klient(string i, string n, string a, string nr_dow, float ob, Klient_Typ* typ_k);
        ~Klient();
        Klient();


};

#endif
