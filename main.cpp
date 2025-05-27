#include "function.h"
#include "my_library.h"

int main() {
    string failas;
    cout << "Iveskite failo pavadinima: ";
    cin >> failas;
    suskaiciuoti_zodzius(failas, "zodziu_dazniai.txt");
    return 0;
}
