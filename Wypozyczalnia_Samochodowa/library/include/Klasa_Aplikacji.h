#ifndef KLASA_APLIKACJI_H
#define KLASA_APLIKACJI_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Wypozyczenie.h"

using namespace std;

class Klasa_Aplikacji
{
	private:
        vector<Wypozyczenie*> lista_biezacych_wypozyczen;
        vector<Wypozyczenie*> lista_archiwalnych_wypozyczen;

	public:
	friend bool mniejsze( Wypozyczenie one, Wypozyczenie two );
    friend bool mniejsze_po_dacie( Wypozyczenie one, Wypozyczenie two );
    bool czy_mozna_zwrocic(Wypozyczenie* wyp);
	void dodaj_do_lista_biezacych_wypozyczen(Wypozyczenie* wyp);
    void wyswietl_biezace_wypozyczenia();
    void dodaj_do_lista_archiwalnych_wypozyczen(Wypozyczenie* wyp);
    void wyswietl_archiwalne_wypozyczenia();
    void sortuj_biezace_wyp_po_dacie();
    void sortuj_biezace_wyp_po_klientach();
    bool czy_pojazd_wypozyczony(Pojazdy* wyp);
    void zwroc_pojazd(Wypozyczenie* wyp);
    void wyswietl_biezace_wypozyczenia_klienta(Klient* wyp_klienta);
    void zapisz_do_pliku();
	Klasa_Aplikacji();
	~Klasa_Aplikacji();
};

#endif
