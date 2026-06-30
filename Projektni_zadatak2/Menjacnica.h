#pragma once
#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Transakcija.h"

using namespace std;

class Menjacnica {
private:
    map<string, double> kursnaLista;                  // STL map: "EUR" -> 117.5
    vector<unique_ptr<Transakcija>> istorija;          // STL vector pokazivaca na Transakcija

public:
    void dodajKurs(string valuta, double kurs);
    double vratiKurs(string valuta) const;             // baca NepoznataValutaException ako ne postoji
    void prikaziKursnuListu() const;

    void kupi(string valuta, double iznosRSD);
    void prodaj(string valuta, double iznosValute);

    void prikaziIstoriju() const;

    void sacuvajKursnuListu(string putanja) const;
    void ucitajKursnuListu(string putanja);
    void sacuvajIstoriju(string putanja) const;
};