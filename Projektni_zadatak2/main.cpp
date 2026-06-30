#include <iostream>
#include "Menjacnica.h"
#include "Izuzeci.h"

using namespace std;

int main() {
    Menjacnica menjacnica;

    // Ucitavamo kursnu listu iz fajla pri pokretanju (ako fajl postoji)
    menjacnica.ucitajKursnuListu("kursna_lista.txt");

    // Ako kursna lista nije ucitana (fajl ne postoji), dodajemo pocetne vrednosti
    menjacnica.dodajKurs("EUR", 117.5);
    menjacnica.dodajKurs("USD", 108.2);
    menjacnica.dodajKurs("CHF", 124.0);

    int izbor;

    do {
        cout << "\n--- MENJACNICA ---\n";
        cout << "1. Prikazi kursnu listu\n";
        cout << "2. Kupi valutu (RSD -> valuta)\n";
        cout << "3. Prodaj valutu (valuta -> RSD)\n";
        cout << "4. Prikazi istoriju transakcija\n";
        cout << "5. Sacuvaj sve u fajl\n";
        cout << "0. Izlaz\n";
        cout << "Izaberite opciju: ";
        cin >> izbor;

        // try/catch blok - hvatamo nase izuzetke da program ne "pukne"
        try {
            switch (izbor) {
            case 1:
                menjacnica.prikaziKursnuListu();
                break;
            case 2: {
                string valuta;
                double iznos;
                cout << "Unesite oznaku valute (npr. EUR): ";
                cin >> valuta;
                cout << "Unesite iznos u RSD: ";
                cin >> iznos;
                menjacnica.kupi(valuta, iznos);
                break;
            }
            case 3: {
                string valuta;
                double iznos;
                cout << "Unesite oznaku valute (npr. EUR): ";
                cin >> valuta;
                cout << "Unesite iznos valute: ";
                cin >> iznos;
                menjacnica.prodaj(valuta, iznos);
                break;
            }
            case 4:
                menjacnica.prikaziIstoriju();
                break;
            case 5:
                menjacnica.sacuvajKursnuListu("kursna_lista.txt");
                menjacnica.sacuvajIstoriju("istorija.txt");
                break;
            case 0:
                menjacnica.sacuvajKursnuListu("kursna_lista.txt");
                menjacnica.sacuvajIstoriju("istorija.txt");
                cout << "Izlazak iz programa...\n";
                break;
            default:
                cout << "Nepostojeca opcija!\n";
            }
        }
        // catch hvata BILO KOJU nasu gresku jer sve naseduju MenjacnicaException
        catch (const MenjacnicaException& e) {
            cout << "GRESKA: " << e.what() << endl;
        }

    } while (izbor != 0);

    return 0;
}