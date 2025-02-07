# IsThatPrime 🔢

Un programma semplice in C++ per verificare se un numero è primo, con spiegazioni matematiche dettagliate e istruzioni passo-passo.

---

## Indice 📑
- [Cosa è un numero primo?](#-cosa-è-un-numero-primo)
- [Come Compilare ed Eseguire](#-come-compilare-ed-eseguire)
- [Spiegazione Matematica Completa](#-spiegazione-matematica-completa)
  - [Perché si usa la radice quadrata?](#perché-si-usa-la-radice-quadrata)
  - [Ottimizzazioni nel codice](#ottimizzazioni-nel-codice)
- [Esempi di Utilizzo](#-esempi-di-utilizzo)
- [Domande Frequenti](#-domande-frequenti)
- [Licenza](#-licenza)

---

## 🧮 Cosa è un numero primo?

Un **numero primo** è un numero:
- **Maggiore di 1**,
- **Divisibile solo per 1 e per se stesso**.

**Esempi:**  
✅ **Primi**: 2, 3, 5, 7, 11...  
❌ **Non primi**: 4 (divisibile per 2), 6 (divisibile per 2 e 3), 9 (divisibile per 3).

---

## 🛠 Come Compilare ed Eseguire

### Prerequisiti
- Un compilatore C++:
  - **Windows**: Installa [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) o [Code::Blocks](https://www.codeblocks.org/).
  - **macOS/Linux**: Usa `g++` (già installato o installalo con `sudo apt install g++` su Linux).

### Istruzioni
1. **Scarica il codice**:
   ```bash
   git clone https://github.com/MCarraroDev/IsThatPrime.git
   cd IsThatPrime
   ```

2. **Compila**:
   ```bash
   g++ src/main.cpp -o isthatprime
   ```

3. **Esegui**:
   - **Windows**: Clicca su `isthatprime.exe`
   - **macOS/Linux**:
     ```bash
     ./isthatprime
     ```

## 🧠 Spiegazione Matematica Completa

### Perché si usa la radice quadrata?
Se un numero n non è primo, deve avere almeno un divisore ≤ √n.

**Dimostrazione**:
- Supponiamo che n abbia un divisore d > √n.
- Allora esiste un altro divisore k = n/d.
- Poiché d > √n, allora k = n/d < √n (perché d × k = n → k = n/d < n/√n = √n).
- **Conclusione**: Se non ci sono divisori ≤ √n, non ce ne sono > √n!

**Esempio con n = 36**:
- √36 = 6
- Divisori possibili: 2, 3, 4, 6
- Se d = 12 (>6), allora k = 36/12 = 3 (<6)
→ Basta controllare fino a 6!

### Ottimizzazioni nel codice
- **Escludi i numeri pari**: Dopo aver verificato se n è 2 o pari, si controllano solo i dispari.
- **Fermati a √n**: Riduci i controlli da O(n) a O(√n), migliorando l'efficienza.

## 🖥 Esempi di Utilizzo

**Esempio 1**: Numero primo
```
Inserisci un numero: 17
Risultato: Il numero 17 è primo

Statistiche:
- Tempo di esecuzione: 42 microsecondi
- Memoria utilizzata: 8 bytes
```

**Esempio 2**: Numero non primo
```
Inserisci un numero: 25
Risultato: Il numero 25 non è primo

Statistiche:
- Tempo di esecuzione: 38 microsecondi
- Memoria utilizzata: 8 bytes
```

**Esempio 3**: Numero grande
```
Inserisci un numero: 123456789012
Risultato: Il numero 123456789012 non è primo

Statistiche:
- Tempo di esecuzione: 35 microsecondi
- Memoria utilizzata: 8 bytes
```

## ❓ Domande Frequenti

**Perché non si controllano tutti i numeri fino a n-1?**
Per risparmiare tempo! Esempio:
- Per n = 10.000, invece di 9.999 controlli, ne bastano 100 (fino a √10.000 = 100).

**Cosa succede se inserisco un numero negativo o 0?**
Il programma risponde direttamente: "Non è primo" (i numeri primi sono >1).

**Perché si saltano i numeri pari?**
Perché tutti i pari >2 non sono primi (sono divisibili per 2). Saltarli dimezza i controlli!

## 📄 Licenza
Questo progetto è rilasciato con licenza MIT. Puoi usarlo, modificarlo e condividilo liberamente!

Creato con ❤️ da Marco Carraro
