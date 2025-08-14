#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string entrada;
    while (getline(cin, entrada)) {
        if (entrada == "*") break;

        istringstream iss(entrada);
        vector<string> palavras;
        string palavra;

        // Coloca todas as palavras no vetor
        while (iss >> palavra) {
            palavras.push_back(palavra);
        }

        // Verifica se todas começam com a mesma letra
        char primeiraLetra = tolower(palavras[0][0]);
        bool tautograma = true;
        for (size_t i = 1; i < palavras.size(); ++i) {
            if (tolower(palavras[i][0]) != primeiraLetra) {
                tautograma = false;
                break;
            }
        }

        if (tautograma) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}