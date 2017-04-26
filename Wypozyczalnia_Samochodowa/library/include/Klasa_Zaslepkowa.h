#ifndef KLASA_ZASLEPKOWA_H
#define KLASA_ZASLEPKOWA_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Klient.h"
#include "Klient_Typ.h"
#include "Klient_Domyslny.h"
#include "Rower.h"
#include "Motorower.h"
#include "Samochod.h"
#include "Lista_Klientow.h"
#include "Lista_Pojazdow.h"
#include "Wypozyczenie.h"
#include "Klasa_Aplikacji.h"

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;


class Klasa_Zaslepkowa
{
    public:
        Klasa_Zaslepkowa();

        void set_symulacje()
        {

            Klient_Domyslny k_d;
            Klient_Typ* k =  &k_d;
            Klient *k1 = new Klient("Marian", "Kowalski", "Lodz, ul. Kilinskiego 30", "ASZ234213",0,k);
            Klient *k2 = new Klient("Zbigniew", "Wesolowski", "Warszawa, Plan Lotnikow 4", "GDS252347",0,k);
            Klient *k3 = new Klient("Olga", "Klepka", "Lodz, al. Politechniki 23", "GFD756436",0,k);
            Klient *k4 = new Klient("Mateusz", "Jankowski", "Ozorkow, ul. Kolejarzy 21", "FDS320124",0,k);
            Klient *k5 = new Klient("Aleksandra", "Konieczna", "Lodz, ul. Piotrkowska 241", "GFH475823",0,k);

            Pojazdy* p1 = new Rower("ROMET ROAD X230");
            Pojazdy* p2 = new Rower("ROMET MTB  K-32");
            Pojazdy* p3 = new Motorower(500,"Komar 2350");
            Pojazdy* p4 = new Motorower(700,"KTM RC8");
            Pojazdy* p5 = new Motorower(1100,"YAMAHA MT-07");
            Pojazdy* p6 = new Samochod(1500, "A","Toyota Aygo, rok 2016, klasa A" );
            Pojazdy* p7 = new Samochod(1300, "B","Toyota Yaris, rok 2016,  klasa B" );
            Pojazdy* p8 = new Samochod(1800, "C","Volkswagen Golf 5, rok 2016, klasa C" );
            Pojazdy* p9 = new Samochod(2000, "D","Skoda Octawia, rok 2016, klasa D" );
            Pojazdy* p10 = new Samochod(3200, "E","BMW 520D﻿, rok 2016, klasa E)" );

            Lista_Klientow* Rejestr_Klientow = new Lista_Klientow;
            Rejestr_Klientow->DodajKlienta(k1);
            Rejestr_Klientow->DodajKlienta(k2);
            Rejestr_Klientow->DodajKlienta(k3);
            Rejestr_Klientow->DodajKlienta(k4);
            Rejestr_Klientow->DodajKlienta(k5);

            Lista_Pojazdow* Rejestr_Pojazdow = new Lista_Pojazdow;
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p1,-123);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p2,15);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p3,30);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p4,50);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p5,70);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p6,70);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p7,80);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p8,120);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p9,170);
            Rejestr_Pojazdow->dodaj_pojazd_ustal_cene_bazowa(p10, 260);

            Klasa_Aplikacji* Rejestry_wypozyczen = new Klasa_Aplikacji();

            srand(time(NULL));
            Pojazdy* t_P[] = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
            Klient*  t_K[] = {k1,k2,k3,k4,k5};
            Wypozyczenie* t_W[20];
            date t_D[10];
            for (int i=1; i<11; i++)
            {
                t_D[i-1] = day_clock::local_day()-days(i);
            }


            int licznik=0;
            while( licznik <5 )
            {
                Pojazdy* zm_P = t_P[rand()%10];
                if(Rejestry_wypozyczen->czy_pojazd_wypozyczony(zm_P) == false)
                    {
                        Klient* zm_K = t_K[rand() % 5];
                        date zm_D = t_D[rand()%10];
                        t_W[licznik] = new Wypozyczenie(zm_K,zm_P, zm_D, Rejestry_wypozyczen );
                        licznik++;
                    }

            }

            for(int i=0; i <10; i++)
            {

                Wypozyczenie* zm_W = t_W[rand() % 5];
                if(Rejestry_wypozyczen->czy_mozna_zwrocic(zm_W) == true )
                    {

                        Rejestry_wypozyczen->zwroc_pojazd(zm_W);
                    }


                Pojazdy* zm_P = t_P[rand()%10];
                if(Rejestry_wypozyczen->czy_pojazd_wypozyczony(zm_P) == false)
                    {
                        Klient* zm_K = t_K[rand() % 5];
                        date zm_D = t_D[rand()%10];
                        t_W[licznik] = new Wypozyczenie(zm_K,zm_P, zm_D, Rejestry_wypozyczen );
                        licznik++;
                    }

                Rejestry_wypozyczen->wyswietl_biezace_wypozyczenia();
                Rejestry_wypozyczen->wyswietl_archiwalne_wypozyczenia();
            }

            int i = 0;
            while(i <20)
            {

                if(Rejestry_wypozyczen->czy_mozna_zwrocic(t_W[i]) == true)
                    Rejestry_wypozyczen->zwroc_pojazd(t_W[i]);
                i++;

            }


            Rejestry_wypozyczen->zapisz_do_pliku();


        }

};

#endif // KLASA_ZASLEPKOWA_H
