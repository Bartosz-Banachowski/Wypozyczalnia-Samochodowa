#include <boost/test/unit_test.hpp>
#include "../include/Wypozyczenie.h"
#include "../include/Pojazdy.h"
#include "../include/Klient.h"
#include "../include/Klasa_Zaslepkowa.h"
#include "../include/Klasa_Aplikacji.h"
//#include <boost/date_time/gregorian/gregorian.hpp>

BOOST_AUTO_TEST_SUITE(WypozyczenieSuiteCorrect)

BOOST_AUTO_TEST_CASE(NoweWypozyczenie)
{
            Klient_Domyslny k_d;
            Klient_Typ* k =  &k_d;
            Klient *k1 = new Klient("Marian", "Kowalski", "Lodz, ul. Kilinskiego 30", "ASZ234213",0,k);
            Pojazdy* p1 = new Rower("ROMET ROAD X230");
            Klasa_Aplikacji* Rejestry_wypozyczen = new Klasa_Aplikacji();
    Wypozyczenie* w44 = new Wypozyczenie(k1,p1, day_clock::local_day() , Rejestry_wypozyczen );
    BOOST_CHECK_EQUAL(k1, w44->get_kto_wypozyczyl());
    BOOST_CHECK_EQUAL(p1, w44->get_jaki_pojazd());
}


BOOST_AUTO_TEST_CASE(ListaWypozyczen)
{

            Klient_Domyslny k_d;
            Klient_Typ* k =  &k_d;
            Klient *k2 = new Klient("Zbigniew", "Wesolowski", "Warszawa, Plan Lotnikow 4", "GDS252347",0,k);
            Pojazdy* p6 = new Samochod(1500, "A","Toyota Aygo, rok 2016, klasa A" );

            Klasa_Aplikacji* Rejestry_wypozyczen = new Klasa_Aplikacji();
            Wypozyczenie* w45 = new Wypozyczenie(k2,p6, day_clock::local_day() , Rejestry_wypozyczen );


            std::vector <Wypozyczenie*> lista_wyp;
            std::vector <Wypozyczenie*> lista_arch;

            lista_wyp.push_back(w45);

for (std::vector<Wypozyczenie*>::iterator it=lista_wyp.begin(); it != lista_wyp.end(); ++it)
        {
            BOOST_CHECK_EQUAL(w45->getUUID_K(), (*it)->getUUID_K());
            BOOST_CHECK_EQUAL(w45->getUUID_P(), (*it)->getUUID_P());
            BOOST_CHECK_EQUAL(w45->getUUID_W(), (*it)->getUUID_W());
        }
            lista_wyp=lista_arch;

            for (std::vector<Wypozyczenie*>::iterator it=lista_arch.begin(); it != lista_arch.end(); ++it)
        {
            BOOST_CHECK_EQUAL(w45->getUUID_K(), (*it)->getUUID_K());
            BOOST_CHECK_EQUAL(w45->getUUID_P(), (*it)->getUUID_P());
            BOOST_CHECK_EQUAL(w45->getUUID_W(), (*it)->getUUID_W());
        }

}



BOOST_AUTO_TEST_SUITE_END()
