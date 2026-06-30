#pragma once
#include "Transakcija.h"

// Izvedena klasa - predstavlja prodaju strane valute za dinare
class ProdajaValute : public Transakcija {
public:
    ProdajaValute(string valuta, double iznos, double kurs)
        : Transakcija(valuta, iznos, kurs) {
    }

    double izvrsi() const override;
    string opis() const override;
};