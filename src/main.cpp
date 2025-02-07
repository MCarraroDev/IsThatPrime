/**
 * IsThatPrime - Un verificatore di numeri primi
 * 
 * Questo programma determina se un numero è primo o meno, utilizzando
 * un algoritmo ottimizzato che controlla solo i divisori dispari fino
 * alla radice quadrata del numero.
 */

#include <iostream>
#include <cmath>
#include <chrono>
#include <string>
#include <iomanip>  // Per formattare l'output
using namespace std;

// Costanti per i colori dell'output
namespace Colors {
    const char* GREEN = "\033[32m";
    const char* RED = "\033[31m";
    const char* CYAN = "\033[36m";
    const char* RESET = "\033[0m";
}

// ASCII Art per il messaggio di benvenuto
const string WELCOME_ART = R"(
    ____    ________          __  ____       _              ___ 
   /  _/___/_  __/ /_  ____ _/ /_/ __ \_____(_)___ ___  ___/__ \
   / // ___// / / __ \/ __ `/ __/ /_/ / ___/ / __ `__ \/ _ \/ _/
 _/ /(__  )/ / / / / / /_/ / /_/ ____/ /  / / / / / / /  __/_/  
/___/____//_/ /_/ /_/\__,_/\__/_/   /_/  /_/_/ /_/ /_/\___(_)   
                                                          v1.0
)";

// Costanti numeriche
const unsigned long long NUMERO_MAX = 18'446'744'073'709'551'615ULL;

/**
 * Verifica se un numero è un caso base (0, 1, o 2)
 * 
 * @param n Il numero da verificare
 * @return true se è un caso base, false altrimenti
 */
bool isCasoBase(unsigned long long n) {
    return n <= 2;
}

/**
 * Gestisce i casi base per la verifica dei numeri primi
 * 
 * @param n Il numero da verificare
 * @return true se il numero è primo (solo per n=2), false altrimenti
 */
bool gestisciCasiBase(unsigned long long n) {
    return n == 2;  // Solo 2 è primo tra i numeri <= 2
}

/**
 * Verifica se un numero è primo
 * 
 * @param n Il numero da verificare
 * @return true se il numero è primo, false altrimenti
 */
bool primo(unsigned long long n) {
    // Gestione casi base
    if (isCasoBase(n)) return gestisciCasiBase(n);
    if (n % 2 == 0) return false;  // numeri pari > 2 non sono primi

    // Controlla solo i divisori dispari fino alla radice quadrata
    unsigned long long radiceQuadrata = sqrt(n);
    for (unsigned long long divisore = 3; divisore <= radiceQuadrata; divisore += 2) {
        if (n % divisore == 0) return false;
    }

    return true;
}

/**
 * Misura il tempo di esecuzione di una funzione
 * 
 * @param func La funzione da misurare
 * @return Il tempo di esecuzione in microsecondi
 */
template<typename Func>
long long misuraTempo(Func func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

/**
 * Mostra il banner di benvenuto
 */
void mostraBenvenuto() {
    cout << Colors::CYAN << WELCOME_ART << Colors::RESET << endl;
    cout << "Benvenuto! Questo programma verifica se un numero è primo." << endl;
    cout << "Supporta numeri fino a " << NUMERO_MAX << endl << endl;
}

/**
 * Mostra il risultato del test
 * 
 * @param numero Il numero testato
 * @param isPrimo Il risultato del test
 */
void mostraRisultato(unsigned long long numero, bool isPrimo) {
    cout << "\nRisultato: Il numero " << numero << " " 
         << (isPrimo ? Colors::GREEN : Colors::RED)
         << (isPrimo ? "è primo" : "non è primo")
         << Colors::RESET << endl;
}

/**
 * Mostra le statistiche di esecuzione
 * 
 * @param tempoEsecuzione Il tempo di esecuzione in microsecondi
 * @param numero Il numero testato
 */
void mostraStatistiche(long long tempoEsecuzione, unsigned long long numero) {
    cout << "\nStatistiche:" << endl;
    cout << "- Tempo di esecuzione: " << tempoEsecuzione << " microsecondi" << endl;
    cout << "- Memoria utilizzata: " << sizeof(numero) << " bytes" << endl;
}

int main() {
    mostraBenvenuto();

    // Input del numero
    unsigned long long numero;
    cout << "Inserisci un numero: ";
    cin >> numero;

    // Esegui il test e misura il tempo
    bool risultato;
    long long tempoEsecuzione = misuraTempo([&]() { 
        risultato = primo(numero); 
    });

    // Mostra risultati e statistiche
    mostraRisultato(numero, risultato);
    mostraStatistiche(tempoEsecuzione, numero);

    return 0;
}