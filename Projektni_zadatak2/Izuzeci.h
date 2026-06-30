#pragma once
#include <string>
#include <exception>

using namespace std;

// Bazna klasa izuzetka za sve greske vezane za menjacnicu
class MenjacnicaException : public exception {
protected:
    string poruka;
public:
    MenjacnicaException(string p) : poruka(p) {}
    // virtual funkcija koju nasledjujemo iz std::exception, ovde je redefinisemo (override)
    virtual const char* what() const noexcept override {
        return poruka.c_str();
    }
};

// Izuzetak za slucaj kad valuta ne postoji u kursnoj listi
class NepoznataValutaException : public MenjacnicaException {
public:
    NepoznataValutaException(string valuta)
        : MenjacnicaException("Valuta '" + valuta + "' ne postoji u kursnoj listi.") {
    }
};

// Izuzetak za slucaj kad je unet nevazeci (negativan ili nula) iznos
class NevazeciIznosException : public MenjacnicaException {
public:
    NevazeciIznosException()
        : MenjacnicaException("Iznos mora biti veci od nule.") {
    }
};