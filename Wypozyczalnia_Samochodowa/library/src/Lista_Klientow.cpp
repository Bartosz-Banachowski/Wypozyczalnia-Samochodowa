#include "../include/Lista_Klientow.h"


Lista_Klientow::Lista_Klientow()
{

}

Lista_Klientow::~Lista_Klientow()
{
    for ( list< Klient* >::iterator it = lista_wszystkich_klientow.begin(); it != lista_wszystkich_klientow.end(); ++it) { delete (*it);}
}

void Lista_Klientow::DodajKlienta(Klient* klient)
{
    lista_wszystkich_klientow.push_back(klient);
}


void Lista_Klientow::Wyswietl_wszystkich_klientow()
{
    list<Klient*>::iterator it;
    for (it=lista_wszystkich_klientow.begin(); it != lista_wszystkich_klientow.end(); ++it)
        cout<< (*it)->toString() <<endl;

}

