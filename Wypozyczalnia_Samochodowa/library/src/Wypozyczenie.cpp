#include "../include/Wypozyczenie.h"
#include <iostream>
#include "Klasa_Aplikacji.h"


Wypozyczenie::Wypozyczenie(Klient* kto_wypozyczyl, Pojazdy* jaki_pojazd,date data_poczatkowa, Klasa_Aplikacji* rejestr )
                           :kto_wypozyczyl(kto_wypozyczyl),
                            jaki_pojazd(jaki_pojazd),
                            data_poczatkowa(data_poczatkowa)
{
    Wypozyczenie::setUUID_W();
    Wypozyczenie::set_koszt_faktyczny();
    rejestr->dodaj_do_lista_biezacych_wypozyczen(this);
    kto_wypozyczyl->inkr_wyp_aktualnych();
}

Wypozyczenie::~Wypozyczenie()
{
    delete jaki_pojazd;
    delete kto_wypozyczyl;
}

void Wypozyczenie::set_koszt_faktyczny() { this->koszt_faktyczny = (this->jaki_pojazd->get_cena_wyliczona())-(this->kto_wypozyczyl->get_ile_upustu());}
void Wypozyczenie::set_Obrot(float ile) { kto_wypozyczyl->uaktualnij_obrot_klienta(ile); }
string Wypozyczenie::get_nazwisko_k() {return kto_wypozyczyl->get_nazwisko();}
boost::uuids::uuid  Wypozyczenie::getUUID_P() { return jaki_pojazd->getUUID(); }
boost::uuids::uuid  Wypozyczenie::getUUID_K() { return kto_wypozyczyl->getUUID(); }
void Wypozyczenie::set_liczba_wyp_a() { kto_wypozyczyl->dekr_wyp_aktualnych(); }
int Wypozyczenie::get_liczba_wyp_a() { return kto_wypozyczyl->get_liczba_wyp_aktualnych(); }
string Wypozyczenie::get_nazwa_p() {return jaki_pojazd->get_nazwa_pojazdu(); }
string Wypozyczenie::get_imie_k() {return kto_wypozyczyl->get_imie();}


