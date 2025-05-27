#include "function.h"
#include "my_library.h"

int main() {
    string failas;
    cout << "Iveskite failo pavadinima: ";
    cin >> failas;
    suskaiciuoti_zodzius(failas, "zodziu_dazniai.txt");
    cross_reference_lentele(failas, "cross_reference.txt");
    return 0;
}
