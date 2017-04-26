#ifndef LISTA_POJAZDOW_H
#define LISTA_POJAZDOW_H

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include "Pojazdy.h"

using namespace std;


class Lista_Pojazdow
{
	private:
        list <Pojazdy*> lista_wszystkich_pojazdow;

	public:
        void dodaj_pojazd_ustal_cene_bazowa(Pojazdy* poj, float cena_baz);                  //ustalam cene bazowa w chwili dodania pojazdu do klienta
        void wyswietl_wszystkie_pojazdy();
        list <Pojazdy*> get_lista_wszystkich_pojazdow() { return lista_wszystkich_pojazdow; }
        Lista_Pojazdow();
        ~Lista_Pojazdow();
};

#endif
