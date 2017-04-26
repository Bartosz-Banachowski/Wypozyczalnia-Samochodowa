#ifndef LISTA_KLIENTOW_H
#define LISTA_KLIENTOW_H

#include <list>
#include <iostream>
#include <sstream>
#include <string>

#include "Klient.h"

using namespace std;

class Lista_Klientow
{
	private:
        list <Klient*> lista_wszystkich_klientow;

	public:
        void DodajKlienta(Klient* klient);
        void Wyswietl_wszystkich_klientow();
        Lista_Klientow();
        ~Lista_Klientow();
};

#endif
