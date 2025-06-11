# Objektinio programavimo (išankstinė) egzamino užduotis

# Kompiuterio specifikacijos

| Komponentas |             Specifikacija                 |
| :---------- |         :---------------------:           |
| CPU         | AMD Ryzen 5 2600 Six-Core Processor </br> |
| RAM         |             16GB DDR4 </br>               |
| DISK        |             SATA SSD </br>                |

# Projekto atsisiuntimo ir paleidimo instrukcija

## 1. Reikalingų įrankių atsisiuntimas

- [Atsisiusti g++ (GCC kompiliatorius)](https://sourceforge.net/projects/mingw-w64/)
- [Atsisiųsti Make](https://gnuwin32.sourceforge.net/packages/make.htm)

---

## 2. Projekto atsisiuntimas


- Kopijuoti projekto direktoriją `git clone https://github.com/Nerius123/OPP_exam.git`
---

## 3. Projekto paleidimas

Atsidaryti komandinę eilutę (cmd), nueiti į folder'į kuriam yra programa ir į ją įvesti:
```bash
g++ main.cpp function.cpp -o programa && programa
```
Jei naudojate cmake: 

```bash
mkdir build
cd build
cmake ..
cmake --build .
./analyze;
``` 

# Programos naudojimas

1. Į `input/` katalogą įdėkite bent vieną `.txt` failą analizei.
2. Paleidus programą, bus pateiktas failų sąrašas.
3. Įveskite norimo failo numerį.
4. Programa automatiškai:
   - Suskaičiuos pasikartojančius žodžius.
   - Sugeneruos lentelę su žodžių paminėjimo eilutėmis.
   - Ištrauks visus URL adresus.
   - Išfiltruos ir įrašys visus žodžius, kuriuose yra nurodyta dalis (pvz. `"tor"`).
5. Rezultatai bus išsaugoti `output/` kataloge:
   - `zodziu_dazniai.txt`
   - `cross_reference.txt`
   - `rasti_url.txt`
   - `zodziai_su_dalis.txt`

# Programos aprašymas

Ši programa analizuoja teksto failus ir atlieka tris pagrindines užduotis:
1. **Suskaičiuoja, kiek kartų kiekvienas skirtingas žodis pasikartoja tekste.**
2. **Sukuria "cross-reference" tipo lentelę**, nurodančią, kuriose teksto eilutėse žodis buvo paminėtas.
3. **Iš teksto ištraukia visus URL adresus.**
4. **Ieško visų žodžių, kurie turi nurodytą žodžio dalį** (pvz. `"tor"` aptiks `toronto`, `vector`, `tornado` ir pan.). Rezultate pateikiami tik **unikalūs** žodžiai, ignoruojant pasikartojimus.


## Naudojamos C++ savybės

| Naudojama | Paaiškinimas |
|-----------|--------------|
| `std::string` | Žodžių valymui ir saugojimui |
| `std::map`, `std::set` | Asociatyvūs konteineriai žodžių dažniui ir eilučių saugojimui |
| `std::regex` | URL atpažinimui tekste |
| `std::filesystem` | Automatiškai suranda failus iš `input/` aplanko |
| `cin`, `cout`, `ifstream`, `ofstream` | Failų įvestis/išvestis |
| `vector<string>` | Dinaminis failų sąrašas naudotojui pateikti |

---

# Failų/katalogų paskirtis

| Failas / Aplankas   | Paskirtis |
|---------------------|-----------|
| `input/`            | Vartotojo įkeliami `.txt` failai |
| `output/`           | Rezultatai: žodžių skaičius, lentelė, URL |
| `main.cpp`          | Vartotojo sąsaja ir paleidimas |
| `function.cpp`      | Analizės logika |
| `function.h`        | Funkcijų deklaracijos |
| `my_library.h`      | Visos naudojamos bibliotekos |
| `CMakeLists.txt`    | Kompiliavimo instrukcijos per CMake |
| `README.md`         | Šis dokumentas |