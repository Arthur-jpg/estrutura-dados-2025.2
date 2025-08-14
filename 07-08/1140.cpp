#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string entrada;
    while (getline(cin, entrada)) {
        if (entrada == "*") break;

        istringstream iss(entrada);
        string palavra;
        char primeiraLetra = 0;
        bool tautograma = true;

        if (iss >> palavra) {
            primeiraLetra = tolower(palavra[0]);
        }

        while (iss >> palavra) {
            if (tolower(palavra[0]) != primeiraLetra) {
                tautograma = false;
            }
        }

        if (tautograma) {
            printf("Y\n");
        }else {
            printf("N\n");
        }
    }
    return 0;
}