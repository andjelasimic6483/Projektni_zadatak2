#pragma once
#include "Transakcija.h"

// Izvedena klasa - predstavlja kupovinu strane valute za dinare
class KupovinaValute : public Transakcija {
public:
    // Konstruktor poziva konstruktor roditeljske klase (Transakcija) pomocu : Transakcija(...)
    KupovinaValute(string valuta, double iznos, double kurs)
        : Transakcija(valuta, iznos, kurs) {
    }

    // Override - obavezno implementiramo cisto virtuelnu funkciju iz Transakcija
    double izvrsi() const override;
    string opis() const override;
};