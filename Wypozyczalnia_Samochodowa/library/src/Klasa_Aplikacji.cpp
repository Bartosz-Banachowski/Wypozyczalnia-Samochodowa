#include "../include/Klasa_Aplikacji.h"

Klasa_Aplikacji::Klasa_Aplikacji()
{

}

Klasa_Aplikacji::~Klasa_Aplikacji()
{
    for ( vector< Wypozyczenie* >::iterator it = lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end(); ++it) { delete (*it);}
    for ( vector< Wypozyczenie* >::iterator it = lista_archiwalnych_wypozyczen.begin(); it != lista_archiwalnych_wypozyczen.end(); ++it) { delete (*it);}

}


void Klasa_Aplikacji::dodaj_do_lista_biezacych_wypozyczen(Wypozyczenie* wyp)
{

    lista_biezacych_wypozyczen.push_back(wyp);
}

void Klasa_Aplikacji::wyswietl_biezace_wypozyczenia()
{
     vector<Wypozyczenie*>::iterator it;
    for (it=lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end(); ++it)
        cout<< (*it)->toStringg() <<endl;
}

 void Klasa_Aplikacji::wyswietl_biezace_wypozyczenia_klienta(Klient* wyp_klienta)
 {
    vector<Wypozyczenie*>::iterator it;
    for (it=lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end(); ++it)
    {
        if((*it)->getUUID_K() == wyp_klienta->getUUID())
            cout<< (*it)->toStringg() <<endl;
    }



 }

void Klasa_Aplikacji::dodaj_do_lista_archiwalnych_wypozyczen(Wypozyczenie* wyp)
{

    lista_archiwalnych_wypozyczen.push_back(wyp);
}

void Klasa_Aplikacji::wyswietl_archiwalne_wypozyczenia()
{
    vector<Wypozyczenie*>::iterator it;
    for (it=lista_archiwalnych_wypozyczen.begin(); it != lista_archiwalnych_wypozyczen.end(); ++it)
        cout<< (*it)->toString() <<endl;

}

bool mniejsze( Wypozyczenie* one, Wypozyczenie* two ) //funkcja mówiąca który element i w jakim wypadku jest mniejszy od drugiego
    {
         if(one->get_nazwisko_k()<two->get_nazwisko_k()) return true;
         else return false;
    }

void Klasa_Aplikacji::sortuj_biezace_wyp_po_klientach()
{

    sort(lista_biezacych_wypozyczen.begin(), lista_biezacych_wypozyczen.end(), mniejsze );

}

bool mniejsze_po_dacie( Wypozyczenie* one, Wypozyczenie* two ) //funkcja mówiąca który element i w jakim wypadku jest mniejszy od drugiego
    {
         if(one->get_data_poczatkowa()<two->get_data_poczatkowa()) return true;
         else return false;
    }

void Klasa_Aplikacji::sortuj_biezace_wyp_po_dacie()
{

    sort(lista_biezacych_wypozyczen.begin(), lista_biezacych_wypozyczen.end(), mniejsze_po_dacie );

}

bool Klasa_Aplikacji::czy_pojazd_wypozyczony(Pojazdy* wyp)
{
     vector<Wypozyczenie*>::iterator it;
     for (it=lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end(); ++it)
        if((*it)->getUUID_P() == wyp->getUUID()) { return true; }
        return false;

}

void Klasa_Aplikacji::zwroc_pojazd(Wypozyczenie* wyp)
{
    wyp->set_data_koncowa(day_clock::local_day());
    wyp->set_calkowity_koszt_wypozyczenia();                           // liczymy calkowity koszt wpozyczenia
    wyp->set_liczba_wyp_a();                                        // dekrementujemy zmienna odpowiedzialna za liczbe aktulanych wypozyczen danego kilienta
    vector<Wypozyczenie*>::iterator it;
    if(lista_biezacych_wypozyczen.size() != 1 )
    {
        for (it=lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end()+1; ++it)
        {
            if((*it)->getUUID_P() == wyp->getUUID_P())
            {
                dodaj_do_lista_archiwalnych_wypozyczen(*it);
                wyp->set_Obrot(wyp->get_calkowity_koszt_wypozyczenia());       // ustawiamy obrot klienta
                lista_biezacych_wypozyczen.erase(it);
            }

        }

    }
    else {

        it=lista_biezacych_wypozyczen.begin();
        if((*it)->getUUID_P() == wyp->getUUID_P())
            {
                dodaj_do_lista_archiwalnych_wypozyczen(*it);
                wyp->set_Obrot(wyp->get_calkowity_koszt_wypozyczenia());       // ustawiamy obrot klienta
                lista_biezacych_wypozyczen.erase(it);
            }

    }


}

bool Klasa_Aplikacji::czy_mozna_zwrocic(Wypozyczenie* wyp)
{
     vector<Wypozyczenie*>::iterator it;
     if(lista_biezacych_wypozyczen.size() != 1 )
     {
         for (it=lista_biezacych_wypozyczen.begin(); it != lista_biezacych_wypozyczen.end(); ++it)
                if ( wyp->getUUID_W()==(*it)->getUUID_W()) { return true; }

        return false;

     }
     else {

        it=lista_biezacych_wypozyczen.begin();
        if(wyp->getUUID_W()==(*it)->getUUID_W())
            { return true; }
            else { return false ;}

    }

}


void Klasa_Aplikacji::zapisz_do_pliku()
{
    std::fstream plik;
    plik.open("wypozyczenia_archiwalne.txt", std::ios::app);
    if(plik.is_open())
    {
        vector<Wypozyczenie*>::iterator it;
            for (it=lista_archiwalnych_wypozyczen.begin(); it != lista_archiwalnych_wypozyczen.end(); ++it)
            {
                    plik<< (*it)->toString() <<endl << endl;

            }


    plik.close();
    }
    else std::cout<<"brak dostepu do pliku"<<std::endl;

}
