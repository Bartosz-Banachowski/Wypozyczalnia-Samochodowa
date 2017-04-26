#include <boost/test/unit_test.hpp>
//#include "../include/Pojazdy.h"
//#include "../include/Pojazdy_Silnikowe.h"
#include "../include/Samochod.h"
#include "../include/Motorower.h"
#include "../include/Rower.h"

BOOST_AUTO_TEST_SUITE(PojazdSuiteCorrect)

BOOST_AUTO_TEST_CASE(NowySamochod)
{
Samochod* p1= new Samochod(1800, "C","Volkswagen Golf 5, rok 2016, klasa C");
    BOOST_CHECK_EQUAL(1800, p1->get_pojemnosc_silnika());
    BOOST_CHECK_EQUAL("C", p1->get_segment());
    BOOST_CHECK_EQUAL("Volkswagen Golf 5, rok 2016, klasa C", p1->get_nazwa_pojazdu());
}

BOOST_AUTO_TEST_CASE(NowyMotorower)
{
Motorower* p2= new Motorower(700,"KTM RC8");
    BOOST_CHECK_EQUAL(700, p2->get_pojemnosc_silnika());
    BOOST_CHECK_EQUAL("KTM RC8", p2->get_nazwa_pojazdu());
}

BOOST_AUTO_TEST_CASE(NowyRower)
{
Rower* p3= new Rower("ROMET ROAD X230");
    BOOST_CHECK_EQUAL("ROMET ROAD X230", p3->get_nazwa_pojazdu());
}

BOOST_AUTO_TEST_CASE(ListaPojazdow)
{
    vector <Samochod*> lista_poj;
    Samochod* p1= new Samochod(1800, "C","Volkswagen Golf 5, rok 2016, klasa C");
    lista_poj.push_back(p1);
    for (std::vector<Samochod*>::iterator it=lista_poj.begin(); it != lista_poj.end(); ++it)
        {
            BOOST_CHECK_EQUAL(p1->get_pojemnosc_silnika(), (*it)->get_pojemnosc_silnika());
            BOOST_CHECK_EQUAL(p1->get_segment(),(*it)->get_segment());
            BOOST_CHECK_EQUAL(p1->get_nazwa_pojazdu(),(*it)->get_nazwa_pojazdu());

        }
}

BOOST_AUTO_TEST_SUITE_END()
