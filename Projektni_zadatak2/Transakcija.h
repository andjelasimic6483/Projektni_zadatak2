#pragma once
#include <string>
#include <iostream>

using namespace std;

class Transakcija {
protected:
    string valuta;
    double iznos;
    double kurs;

public:
    Transakcija(string valuta, double iznos, double kurs)
        : valuta(valuta), iznos(iznos), kurs(kurs) {
    }

    virtual ~Transakcija() {}

    virtual double izvrsi() const = 0;

    virtual string opis() const = 0;

    double getIznos() const { return iznos; }
    string getValuta() const { return valuta; }
};