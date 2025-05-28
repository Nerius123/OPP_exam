#include "function.h"
#include "my_library.h"

int main() {
    vector<string> txt_failai;
    string input_folder = "input";

    cout << "Galimi failai aplanke '" << input_folder << "':\n";

    // Nuskaityti visus .txt failus is input folder'io
    for (const auto &entry : std::filesystem::directory_iterator(input_folder)) {
        if (entry.path().extension() == ".txt") {
            txt_failai.push_back(entry.path().filename().string());
        }
    }

    // jei tuscia
    if (txt_failai.empty()) {
        cout << "Aplanke 'input/' nerasta .txt failų.\n";
        return 1;
    }

    // Atspausdinti sąrašą
    for (size_t i = 0; i < txt_failai.size(); ++i) {
        cout << "[" << i + 1 << "] " << txt_failai[i] << "\n";
    }

    // Pasirinkimas
    int pasirinkimas = 0;
    while (pasirinkimas < 1 || pasirinkimas > txt_failai.size()) {
        cout << "\nPasirinkite faila ivesdami jo numeri: ";
        cin >> pasirinkimas;

        if (cin.fail() || pasirinkimas < 1 || pasirinkimas > txt_failai.size()) {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
            cin.clear(); // clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // praleidzia bloga ivesti
            pasirinkimas = 0; // reiksme vel nunulinama
        }
    }

    string pasirinktas_failas = input_folder + "/" + txt_failai[pasirinkimas - 1];

    suskaiciuoti_zodzius(pasirinktas_failas, "output/zodziu_dazniai.txt");
    cross_reference_lentele(pasirinktas_failas, "output/cross_reference.txt");
    rasti_url_adresus(pasirinktas_failas, "output/rasti_url.txt");


    return 0;
}
