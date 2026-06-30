#include "KupovinaValute.h"
#include <sstream>

// Vraca koliko strane valute korisnik dobija za uneti iznos dinara
double KupovinaValute::izvrsi() const {
    return iznos / kurs;
}

string KupovinaValute::opis() const {
    ostringstream out;
    out << "Kupovina: " << iznos << " RSD -> "
        << izvrsi() << " " << valuta << " (kurs: " << kurs << ")";
    return out.str();
}