#include "Wyjatek_Ujemna.h"

#include "Pojazdy.h"

void Wyjatek_Ujemna::opis()
{
            cout<<"Ujemny argument: " << this->ujemny_argument << ". Niedozwolona wartosc. " << endl; // do zmiany -3 przekazanie do klasy wartosci ujemnej
            cout<<"Ustawiam cene bazowa na wartosc domyslna (0) " << endl;
            Ujemna->set_cena_bazowa(0);
}
