#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int qtdVirius;

    while (cin >> qtdVirius) {
    
        int idades[qtdVirius];

        int entrada;
        for (int i = 0; i < qtdVirius; i++) {
            cin >> entrada;
            idades[i] = entrada;
        }

        for (int i = 0; i < qtdVirius - 1; i++) {
            for (int j = 0; j < qtdVirius - 1 - i; j++) {
                if (idades[j] > idades[j + 1]) {
                    int varivavel = idades[j];
                    idades[j] = idades[j + 1];
                    idades[j + 1] = varivavel;
                }
            }
        }

        int soma = 0;
        for (int i = 0; i < qtdVirius / 2; i++) {
            soma += idades[qtdVirius - 1 - i] - idades[i];
        }

        cout << soma << endl;



    }


    return 0;
}



