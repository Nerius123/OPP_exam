#include "function.h"
#include "my_library.h"

string apvalyk_zodi(const string &zodis) {
    string rezultatas;
    // Čia laikom papildomus skyrybos simbolius, kurių nenori įtraukti kaip žodžio dalies
    string papildomi_skyrybos = "–„′−";
    for (unsigned char c : zodis) {
        if (!ispunct(c) && !isdigit(c) && papildomi_skyrybos.find(c) == string::npos) {
            rezultatas += tolower(c);
        }
    }
    return rezultatas;
}

void suskaiciuoti_zodzius(const string &failo_pavadinimas, const string &rezultatu_failas) {
    ifstream failas(failo_pavadinimas);
    if (!failas) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    map<string, int> zodziu_kiekis;
    string zodis;
    while (failas >> zodis) {
        string svarus_zodis = apvalyk_zodi(zodis);
        if (!svarus_zodis.empty()) {
            zodziu_kiekis[svarus_zodis]++;
        }
    }
    failas.close();

    ofstream rezultatai(rezultatu_failas);
    for (const auto &pora : zodziu_kiekis) {
        if (pora.second > 1) {
            rezultatai << pora.first << ": " << pora.second << "\n";
        }
    }
    rezultatai.close();
    cout << "Rezultatai irasyti i '" << rezultatu_failas << "'\n";
}
