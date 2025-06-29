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
        cout << "Rezultatai irasyti i ==> '" << rezultatu_failas << "'\n";
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

        rezultatai << left << setw(28) << "Zodis" << " | Eilutes" << endl;
        rezultatai << string(28, '-') << "-+-" << string(40, '-') << endl;

        for (const auto &[zodis, eilutes] : zodziu_eilutes) {
            if (zodziu_kiekis[zodis] > 1) {
                rezultatai << left << setw(28) << zodis << " | ";
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
        cout << "Cross-reference lentele irasyta i ==> '" << rezultatu_failas << "'\n";
    }
    catch (const exception &e) {
        cerr << "Klaida [cross-reference]: " << e.what() << endl;
    }
}

void rasti_url_adresus(const string& failo_pavadinimas, const string& rezultatu_failas) {
    try {
        ifstream failas(failo_pavadinimas);
        if (!failas) {
            throw runtime_error("Nepavyko atidaryti failo: " + failo_pavadinimas);
        }

        ofstream rezultatai(rezultatu_failas);
        if (!rezultatai) {
            throw runtime_error("Nepavyko sukurti rezultatu failo: " + rezultatu_failas);
        }

        vector<string> atmestini = {".docx", ".pdf", ".mp3", ".mp4", ".txt", ".pas", ".zip"};

        const regex url_regex(R"((https?:\/\/[^\s]+)|(www\.[^\s]+)|\b[a-zA-Z0-9\-]+\.[a-zA-Z]{2,}\b)");

        string eilute;
        int eil_nr = 1;

        while (getline(failas, eilute)) {
            smatch atitikmuo;
            string likusi = eilute;

            while (regex_search(likusi, atitikmuo, url_regex)) {
                string url = atitikmuo[0];

                // Pasalinam gale esancius skyrybos zenklus
                while (!url.empty() && ispunct(url.back()) && url.back() != '/' && url.back() != '-') {
                    url.pop_back();
                }

                bool atmesti = false;
                for (const string& ext : atmestini) {
                    if (url.size() >= ext.size() && url.substr(url.size() - ext.size()) == ext) {
                        atmesti = true;
                        break;
                    }
                }

                if (!atmesti) {
                    rezultatai << "Rasta eiluteje " << eil_nr << ": " << url << "\n";
                }

                likusi = atitikmuo.suffix();
            }

            eil_nr++;
        }

        failas.close();
        rezultatai.close();
        cout << "URL'ai irasyti i ==> '" << rezultatu_failas << "'\n";
    }
    catch (const exception& e) {
        cerr << "Klaida [URL paieska]: " << e.what() << endl;
    }
}

void rasti_zodzius_su_dalis(const string &failo_pavadinimas, const string &rezultatu_failas, const string &dalis) {
    try {
        ifstream failas(failo_pavadinimas);
        if (!failas) throw runtime_error("Nepavyko atidaryti failo: " + failo_pavadinimas);

        set<string> zodziai_su_dalis;
        string zodis;
        while (failas >> zodis) {
            string svarus = apvalyk_zodi(zodis);
            if (!svarus.empty() && svarus.find(dalis) != string::npos) {
                zodziai_su_dalis.insert(svarus);
            }
        }

        failas.close();

        ofstream rezultatai(rezultatu_failas);
        if (!rezultatai) throw runtime_error("Nepavyko sukurti failo: " + rezultatu_failas);

        rezultatai << "Zodziai, turintys '" << dalis << "':\n";
        for (const auto &z : zodziai_su_dalis) {
            rezultatai << z << "\n";
        }

        rezultatai.close();
        cout << "Zodziai su dalimi '" << dalis << "' irasyti i ==> '" << rezultatu_failas << "'\n";
    }
    catch (const exception &e) {
        cerr << "Klaida [zodziu paieska su dalimi]: " << e.what() << endl;
    }
}
