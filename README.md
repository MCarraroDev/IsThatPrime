<div align="center">

# IsThatPrime

🔢 Un verificatore di numeri primi in C++ con tre diversi algoritmi, gli algoritmi nella directory "src/algoritmi_sec" sono NON sono sviluppati interamente da me, ma tradotti e commentati per un pubblico italiano

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey)]

[Caratteristiche](#-caratteristiche) • 
[Installazione](#-installazione) • 
[Utilizzo](#-utilizzo) • 
[Algoritmi](#-algoritmi) • 
[Benchmark](#-benchmark) • 
[Contribuisci](#-contribuisci)

</div>

## 🚀 Caratteristiche

- **3 Algoritmi** di verifica dei numeri primi:
  - ✨ Metodo Base (per numeri piccoli)
  - 🎡 Wheel Factorization (per numeri medi)
  - ⚡ Miller-Rabin (per numeri grandi)
- **Interfaccia Colorata** per una migliore leggibilità
- **Statistiche** di esecuzione (tempo e memoria)
- **Supporto** per numeri fino a 2⁶⁴ 

## 📦 Installazione

### Prerequisiti

- Compilatore C++
- Git (opzionale)

### Download

```bash
# Clona il repository (richiede Git)
git clone https://github.com/MCarraroDev/IsThatPrime.git

# Oppure scarica lo ZIP
wget https://github.com/MCarraroDev/IsThatPrime/archive/refs/heads/main.zip
unzip main.zip
```

### Compilazione

```bash
# Entra nella directory (Linux/MacOS)
cd IsThatPrime

# Compila tutti gli algoritmi (Linux/MacOS)
g++ src/main.cpp -o isthatprime_base && \
g++ src/algorithms/wheel_factorization.cpp -o isthatprime_wheel && \
g++ src/algorithms/miller_rabin.cpp -o isthatprime_mr

# Per Windows è consigliata la compilazione con Visual Studio, Code::Blocks, Dev-C++, etc.
```

## 💻 Utilizzo

### Esecuzione Base

```bash
./isthatprime_base
> Inserisci un numero: 997
> Il numero 997 è primo!
> Tempo: 0.023ms
```

### Confronto Algoritmi

```bash
# Test con un numero grande
time ./isthatprime_base   123456789012345
time ./isthatprime_wheel 123456789012345
time ./isthatprime_miller 123456789012345
```

## 🔬 Algoritmi

### 1. Metodo Base
- **Complessità**: O(√n)
- **Approccio**: Divide per numeri dispari fino a √n
- **Uso**: Ideale per numeri < 10⁶
- **Pro**: Semplice da capire
- **Contro**: Lento per numeri grandi

### 2. Wheel Factorization
- **Complessità**: O(√n) con costante minore
- **Approccio**: Usa pattern per saltare numeri non primi
- **Uso**: Ottimo per numeri < 10¹²
- **Pro**: Buon compromesso velocità/complessità
- **Contro**: Più complesso da implementare

### 3. Miller-Rabin
- **Complessità**: O(k log³ n)
- **Approccio**: Test probabilistico (deterministico fino a 2⁶⁴)
- **Uso**: Perfetto per numeri > 10¹²
- **Pro**: Estremamente veloce
- **Contro**: Matematicamente più avanzato

## 📊 Benchmark

| Numero          | Base    | Wheel   | Miller-Rabin |
|-----------------|---------|---------|--------------|
| 997             | 0.023ms | 0.021ms | 0.045ms      |
| 10⁹+7           | 89ms    | 31ms    | 0.12ms       |
| 10¹⁸+9          | >1s     | ~400ms  | 0.15ms       |

## 🤝 Contribuisci

Contributi e suggerimenti sono benvenuti! Per favore:

1. 🍴 Fai un fork del progetto
2. 🔨 Crea un branch per le tue modifiche
3. 📝 Commita i tuoi miglioramenti
4. 📫 Invia una Pull Request

## 📜 Licenza

Questo progetto è sotto licenza MIT - vedi il file [LICENSE](LICENSE) per i dettagli.

---

<div align="center">
Creato con ❤️ da Marco Carraro
</div>
