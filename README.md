# Objektinio programavimo (išankstinė) egzamino užduotis

# Programos aprašymas

Ši programa analizuoja teksto failus ir atlieka tris pagrindines užduotis:
1. **Suskačiuoja, kiek kartų kiekvienas skirtingas žodis pasikartoja tekste.**
2. **Sukuria "cross-reference" tipo lentelę**, nurodančią, kuriose teksto eilutėse žodis buvo paminėtas.
3. **Iš teksto ištraukia visus URL adresus.**

# Kompiuterio specifikacijos

| Komponentas |             Specifikacija                 |
| :---------- |         :---------------------:           |
| CPU         | AMD Ryzen 5 2600 Six-Core Processor </br> |
| RAM         |             16GB DDR4 </br>               |
| DISK        |             SATA SSD </br>                |

# Projekto atsisiuntimo instrukcija

## 1. Reikalingų įrankių atsisiuntimas

- [Atsisiusti g++ (GCC kompiliatorius)](https://sourceforge.net/projects/mingw-w64/)
- [Atsisiusti Make](https://gnuwin32.sourceforge.net/packages/make.htm)

---

## 2. Projekto atsisiuntimas

```bash
- Kopijuoti projekto direktorija `git clone https://github.com/Nerius123/OPP_exam.git`
```
---

# Naudojamos C++ savybės

| Naudojama | Paaiškinimas |
|-----------|--------------|
| `std::string` | Žodžių valymui ir saugojimui |
| `std::map`, `std::set` | Asociatyvūs konteineriai žodžių dažniui ir eilučių saugojimui |
| `std::regex` | URL atpažinimui tekste |
| `std::filesystem` | Automatiškai suranda failus iš `input/` aplanko |
| `cin`, `cout`, `ifstream`, `ofstream` | Failų įvestis/išvestis |
| `vector<string>` | Dinaminis failų sąrašas naudotojui pateikti |

---

## Naudojamos programos ir kam jos skirtos

- input/ # Teksto failai, kuriuos vartotojas pasirenka analizei
- output/ # Automatiškai sugeneruoti rezultatai
- main.cpp # Pagrindinis failas (meniu ir paleidimas)
- function.cpp # Visos analizės funkcijos
- function.h # Funkcijų deklaracijos
- my_library.h # Visos bibliotekos ir alias'ai
- CMakeLists.txt # CMake konfigūracinis failas
- README.md # Šis dokumentas