#include "function.h"
#include "my_library.h"

string apvalyk_zodi(const string &zodis) {
    string rezultatas;
    string papildomi_skyrybos = "–„′−";
    for (unsigned char c : zodis) {
        if (!ispunct(c) && !isdigit(c) && papildomi_skyrybos.find(c) == string::npos) {
            rezultatas += tolower(c);
        }
    }
    return rezultatas;
}

void suskaiciuoti_zodzius(const string &failo_pavadinimas, const string &rezultatu_failas) {
    try {
        ifstream failas(failo_pavadinimas);
        if (!failas) {
            throw runtime_error("Nepavyko atidaryti failo: " + failo_pavadinimas);
        }

        map<string, int> zodziu_kiekis;
        string zodis;
        while (failas >> zodis) {
            string svarus_zodis = apvalyk_zodi(zodis);
            if (!svarus_zodis.empty() && svarus_zodis != "a") {
                zodziu_kiekis[svarus_zodis]++;
            }
        }
        failas.close();

        ofstream rezultatai(rezultatu_failas);
        if (!rezultatai) {
            throw runtime_error("Nepavyko sukurti rezultatu failo: " + rezultatu_failas);
        }

        for (const auto &pora : zodziu_kiekis) {
            if (pora.second > 1) {
                rezultatai << pora.first << ": " << pora.second << "\n";
            }
        }
        rezultatai.close();
        cout << "Rezultatai irasyti i --> '" << rezultatu_failas << "'\n";
    }
    catch (const exception &e) {
        cerr << "Klaida [zodziu skaiciavimas]: " << e.what() << endl;
    }
}

void cross_reference_lentele(const string &failo_pavadinimas, const string &rezultatu_failas) {
    try {
        ifstream failas(failo_pavadinimas);
        if (!failas) {
            throw runtime_error("Nepavyko atidaryti failo: " + failo_pavadinimas);
        }

        map<string, int> zodziu_kiekis;
        map<string, set<int>> zodziu_eilutes;

        string eilute;
        int eilutes_nr = 1;
        while (getline(failas, eilute)) {
            stringstream ss(eilute);
            string zodis;
            while (ss >> zodis) {
                string svarus = apvalyk_zodi(zodis);
                if (!svarus.empty() && svarus != "a") {
                    zodziu_kiekis[svarus]++;
                    zodziu_eilutes[svarus].insert(eilutes_nr);
                }
            }
            eilutes_nr++;
        }
        failas.close();

        ofstream rezultatai(rezultatu_failas);
        if (!rezultatai) {
            throw runtime_error("Nepavyko sukurti rezultatu failo: " + rezultatu_failas);
        }

        const int stulpelio_plotis = 24;
        rezultatai << left << setw(stulpelio_plotis) << "Zodis" << "Eilutes" << endl;
        rezultatai << string(stulpelio_plotis, '-') << " " << string(40, '-') << endl;

        for (const auto &[zodis, eilutes] : zodziu_eilutes) {
            if (zodziu_kiekis[zodis] > 1) {
                rezultatai << left << setw(stulpelio_plotis) << zodis;
                bool pirmas = true;
                for (int e : eilutes) {
                    if (!pirmas) rezultatai << ", ";
                    rezultatai << e;
                    pirmas = false;
                }
                rezultatai << endl;
            }
        }
        rezultatai.close();
        cout << "Cross-reference lentele irasyta i --> '" << rezultatu_failas << "'\n";
    }
    catch (const exception &e) {
        cerr << "Klaida [cross-reference]: " << e.what() << endl;
    }
}
