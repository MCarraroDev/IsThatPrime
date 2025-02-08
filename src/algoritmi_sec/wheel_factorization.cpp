/**
 * IsThatPrime - Wheel Factorization
 * Implementazione del test di primalità usando la wheel factorization
 */

#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

namespace Colors {
    const char* GREEN = "\033[32m";
    const char* RED = "\033[31m";
    const char* CYAN = "\033[36m";
    const char* RESET = "\033[0m";
}

// Costanti numeriche
const unsigned long long NUMERO_MAX = 18'446'744'073'709'551'615ULL;

// La ruota base con i resti modulo 30 (dopo aver controllato 2,3,5)
const vector<int> WHEEL = {1, 7, 11, 13, 17, 19, 23, 29};

/**
 * Verifica se un numero è primo usando la wheel factorization
 * Questa implementazione usa una ruota modulo 30 = 2 * 3 * 5
 */
bool primo(unsigned long long n) {
    // Gestione casi base
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    // Usa la wheel factorization
    unsigned long long radice = sqrt(n);
    unsigned long long k = 0;
    unsigned long long divisore = 0;

    while ((divisore = 30 * k + WHEEL[0]) <= radice) {
        // Prova tutti i possibili resti nella ruota
        for (int resto : WHEEL) {
            unsigned long long d = 30 * k + resto;
            if (d > radice) break;
            if (n % d == 0) return false;
        }
        k++;
    }

    return true;
}

int main() {
    cout << Colors::CYAN << "IsThatPrime - Wheel Factorization" << Colors::RESET << endl;
    cout << "Questo programma verifica se un numero è primo usando la wheel factorization." << endl;
    cout << "Supporta numeri fino a " << NUMERO_MAX << endl << endl;

    unsigned long long numero;
    cout << "Inserisci un numero: ";
    cin >> numero;

    auto start = chrono::high_resolution_clock::now();
    bool risultato = primo(numero);
    auto end = chrono::high_resolution_clock::now();
    auto durata = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nRisultato: Il numero " << numero << " " 
         << (risultato ? Colors::GREEN : Colors::RED)
         << (risultato ? "è primo" : "non è primo")
         << Colors::RESET << endl;

    cout << "\nStatistiche:" << endl;
    cout << "- Tempo di esecuzione: " << durata.count() << " microsecondi" << endl;
    cout << "- Memoria utilizzata: " << sizeof(numero) << " bytes" << endl;

    return 0;
}
