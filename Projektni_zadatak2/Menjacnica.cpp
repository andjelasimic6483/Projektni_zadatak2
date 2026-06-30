#include "Menjacnica.h"
#include "KupovinaValute.h"
#include "ProdajaValute.h"
#include "Izuzeci.h"
#include <iostream>
#include <fstream>

void Menjacnica::dodajKurs(string valuta, double kurs) {
    kursnaLista[valuta] = kurs;
}

double Menjacnica::vratiKurs(string valuta) const {
    // find() trazi kljuc u mapi; ako ga ne nadje, vraca kursnaLista.end()
    auto it = kursnaLista.find(valuta);
    if (it == kursnaLista.end()) {
        throw NepoznataValutaException(valuta);
    }
    return it->second;
}

void Menjacnica::prikaziKursnuListu() const {
    cout << "\n--- KURSNA LISTA ---\n";
    for (const auto& par : kursnaLista) {
        cout << par.first << " : " << par.second << " RSD\n";
    }
}

void Menjacnica::kupi(string valuta, double iznosRSD) {
    if (iznosRSD <= 0) throw NevazeciIznosException();
    double kurs = vratiKurs(valuta);  // moze baciti NepoznataValutaException

    // make_unique pravi novi objekat i odmah ga "umotava" u unique_ptr
    auto transakcija = make_unique<KupovinaValute>(valuta, iznosRSD, kurs);
    cout << transakcija->opis() << endl;

    // move() prebacuje vlasnistvo nad pokazivacem u vector (unique_ptr ne moze da se kopira)
    istorija.push_back(move(transakcija));
}

void Menjacnica::prodaj(string valuta, double iznosValute) {
    if (iznosValute <= 0) throw NevazeciIznosException();
    double kurs = vratiKurs(valuta);

    auto transakcija = make_unique<ProdajaValute>(valuta, iznosValute, kurs);
    cout << transakcija->opis() << endl;

    istorija.push_back(move(transakcija));
}

void Menjacnica::prikaziIstoriju() const {
    if (istorija.empty()) {
        cout << "Istorija transakcija je prazna.\n";
        return;
    }
    cout << "\n--- ISTORIJA TRANSAKCIJA ---\n";
    for (const auto& t : istorija) {
        // t->opis() - poziva se opis() iz Transakcija pokazivaca,
        // ali se IZVRSAVA verzija iz KupovinaValute ili ProdajaValute - to je polimorfizam
        cout << t->opis() << endl;
    }
}

void Menjacnica::sacuvajKursnuListu(string putanja) const {
    ofstream fajl(putanja);
    if (!fajl.is_open()) {
        cout << "Greska pri otvaranju fajla za pisanje!\n";
        return;
    }
    for (const auto& par : kursnaLista) {
        fajl << par.first << " " << par.second << "\n";
    }
    fajl.close();
    cout << "Kursna lista sacuvana u " << putanja << endl;
}

void Menjacnica::ucitajKursnuListu(string putanja) {
    ifstream fajl(putanja);
    if (!fajl.is_open()) {
        cout << "Fajl sa kursnom listom ne postoji, kreniti od prazne liste.\n";
        return;
    }
    string valuta;
    double kurs;
    while (fajl >> valuta >> kurs) {
        kursnaLista[valuta] = kurs;
    }
    fajl.close();
}

void Menjacnica::sacuvajIstoriju(string putanja) const {
    ofstream fajl(putanja);
    if (!fajl.is_open()) {
        cout << "Greska pri otvaranju fajla za pisanje!\n";
        return;
    }
    for (const auto& t : istorija) {
        fajl << t->opis() << "\n";
    }
    fajl.close();
    cout << "Istorija sacuvana u " << putanja << endl;
}