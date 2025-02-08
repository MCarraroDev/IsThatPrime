/**
 * IsThatPrime - Miller-Rabin
 * Implementazione del test di primalità di Miller-Rabin
 */

#include <iostream>
#include <cmath>
#include <chrono>
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

/**
 * Calcola (base ^ exp) % mod in modo sicuro per numeri grandi
 */
unsigned long long powmod(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (__uint128_t)result * base % mod;
        base = (__uint128_t)base * base % mod;
        exp >>= 1;
    }
    return result;
}

/**
 * Test di Miller-Rabin per un singolo testimone
 */
bool miller_rabin_test(unsigned long long n, unsigned long long a) {
    if (n == a) return true;
    
    // Trova d dispari tale che n-1 = d * 2^s
    unsigned long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    // Calcola a^d % n
    unsigned long long x = powmod(a, d, n);
    if (x == 1 || x == n-1) return true;

    // Eleva alla potenza fino a s-1 volte
    for (int r = 1; r < s; r++) {
        x = (__uint128_t)x * x % n;
        if (x == 1) return false;
        if (x == n-1) return true;
    }

    return false;
}

/**
 * Test di Miller-Rabin deterministico per numeri fino a 2^64
 * Usa una lista di testimoni che garantisce la correttezza fino a 2^64
 */
bool primo(unsigned long long n) {
    // Gestione casi base
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1) == 0) return false;  // numeri pari

    // Lista di testimoni che garantisce la correttezza fino a 2^64
    const unsigned long long witnesses[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    
    // Testa ogni testimone
    for (unsigned long long a : witnesses) {
        if (a >= n) break;
        if (!miller_rabin_test(n, a)) return false;
    }
    
    return true;
}

int main() {
    cout << Colors::CYAN << "IsThatPrime - Miller-Rabin" << Colors::RESET << endl;
    cout << "Questo programma verifica se un numero è primo usando il test di Miller-Rabin." << endl;
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
