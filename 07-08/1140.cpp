#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    string entrada;
    while (getline(cin, entrada)) {
        if (entrada == "*") {
            break;
        }

        char primeirasLetras[100]; 
        int numPalavras = 0;
        bool dentroDeUmaPalavra = false;


        for (int i = 0; i < entrada.length(); i++) {
            if (entrada[i] != ' ') {
                if (!dentroDeUmaPalavra) {
                    char letra = entrada[i];
                    if (letra >= 'A' && letra <= 'Z') {
                        letra = letra + 32; 
                    }
                    primeirasLetras[numPalavras] = letra;
                    numPalavras++;
                    dentroDeUmaPalavra = true;
                }
            } else {
                dentroDeUmaPalavra = false;
            }
        }
        bool tautograma = true;
        for (int i = 1; i < numPalavras; i++) {
            if (primeirasLetras[i] != primeirasLetras[0]) {
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
