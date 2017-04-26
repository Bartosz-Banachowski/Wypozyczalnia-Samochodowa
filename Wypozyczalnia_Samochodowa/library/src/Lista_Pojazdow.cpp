#include "../include/Lista_Pojazdow.h"
#include <iostream>

Lista_Pojazdow::Lista_Pojazdow()
{

}

Lista_Pojazdow::~Lista_Pojazdow()
{
     for ( list< Pojazdy* >::iterator it = lista_wszystkich_pojazdow.begin(); it != lista_wszystkich_pojazdow.end(); ++it) { delete (*it);}
}

void Lista_Pojazdow::dodaj_pojazd_ustal_cene_bazowa(Pojazdy* poj, float cena_baz)
{
    try
    {
        poj->set_cena_bazowa(cena_baz);

    }catch(Wyjatek_Ujemna& w)
    {
        w.opis();
    }

    poj->set_cena_wyliczona();
    lista_wszystkich_pojazdow.push_back(poj);
}


void Lista_Pojazdow::wyswietl_wszystkie_pojazdy()
{

    list<Pojazdy*>::iterator it;
    for (it=lista_wszystkich_pojazdow.begin(); it != lista_wszystkich_pojazdow.end(); ++it)
        cout<< (*it)->toString() <<endl;

}
