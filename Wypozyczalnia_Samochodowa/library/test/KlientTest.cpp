#include <boost/test/unit_test.hpp>
#include "../include/Klient.h"
#include "../include/Klient_Typ.h"
//#include "../include/Klasa_Aplikacji.h"
//#include "../include/Klasa_Zaslepkowa.h"
#include "../include/Klient_Domyslny.h"
#include "../include/Klient_Typu_A.h"
#include "../include/Klient_Typu_B.h"
BOOST_AUTO_TEST_SUITE(KlientSuiteCorrect)

BOOST_AUTO_TEST_CASE(NowyKlient)
{
Klient_Domyslny typD;
Klient_Typ* k = &typD;
Klient *k1 = new Klient("Marian", "Kowalski", "Lodz, ul. Kilinskiego 30", "ASZ234213",0,k);
    BOOST_CHECK_EQUAL("Marian", k1->get_imie());
    BOOST_CHECK_EQUAL("Kowalski", k1->get_nazwisko());
    BOOST_CHECK_EQUAL("Lodz, ul. Kilinskiego 30", k1->get_adres());
    BOOST_CHECK_EQUAL("ASZ234213", k1->get_nr_dowodu_osobistego());
    BOOST_CHECK_EQUAL(0, k1->get_obrot_klienta());
}

BOOST_AUTO_TEST_CASE(TypyKlientow)
{
    Klient_Typ* k1 = new Klient_Domyslny;

    BOOST_CHECK_EQUAL("Klient Domyslny ",k1->get_nazwa_typu_klienta());
    BOOST_CHECK_EQUAL(3, k1->get_max_liczba_pojazdow());
    BOOST_CHECK_CLOSE(0, k1->get_upust(),0.0001);

      k1 = new Klient_Typu_A;

    BOOST_CHECK_EQUAL("Klient Typu A ",k1->get_nazwa_typu_klienta());
    BOOST_CHECK_EQUAL(5, k1->get_max_liczba_pojazdow());
    BOOST_CHECK_CLOSE(0, k1->get_upust(),0.0001);

    k1 = new Klient_Typu_B;

    BOOST_CHECK_EQUAL("Klient Typu B ",k1->get_nazwa_typu_klienta());
    BOOST_CHECK_EQUAL(7, k1->get_max_liczba_pojazdow());
    BOOST_CHECK_CLOSE(0, k1->get_upust(),0.0001);

}

BOOST_AUTO_TEST_CASE(checkClientList)
{
    Klient_Domyslny typD;
    Klient_Typ* k = &typD;
    Klient *k1 = new Klient("Marian", "Kowalski", "Lodz, ul. Kilinskiego 30", "ASZ234213",0,k);
    vector <Klient*>lista_kl;
    lista_kl.push_back(k1);
        for (std::vector<Klient*>::iterator it=lista_kl.begin(); it != lista_kl.end(); ++it)
        {
            BOOST_CHECK_EQUAL(k1->get_imie(), (*it)->get_imie());
            BOOST_CHECK_EQUAL(k1->get_nazwisko(), (*it)->get_nazwisko());
            BOOST_CHECK_EQUAL(k1->get_adres(), (*it)->get_adres());
            BOOST_CHECK_EQUAL(k1->get_nr_dowodu_osobistego(), (*it)->get_nr_dowodu_osobistego());
            BOOST_CHECK_EQUAL(k1->get_obrot_klienta(), (*it)->get_obrot_klienta());
        }

}

BOOST_AUTO_TEST_SUITE_END()
