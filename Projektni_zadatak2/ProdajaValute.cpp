#include "ProdajaValute.h"
#include <sstream>

// Vraca koliko dinara korisnik dobija za uneti iznos strane valute
double ProdajaValute::izvrsi() const {
    return iznos * kurs;
}

string ProdajaValute::opis() const {
    ostringstream out;
    out << "Prodaja: " << iznos << " " << valuta << " -> "
        << izvrsi() << " RSD (kurs: " << kurs << ")";
    return out.str();
}