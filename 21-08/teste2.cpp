#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int qtd;
    while (cin >> qtd) {
        int esquerdo[61] = {0};
        int direito[61] = {0};


        for (int i = 0; i<qtd; i++) {
            int numero;
            char lado;
    
            cin >> numero >> lado;
    
            if (lado == 'E'){
                esquerdo[numero]++;
            } else {
                direito[numero]++;
            }

        }

        int pares = 0;

        for(int i = 30; i <= 60; i++ ) {
            if(esquerdo[i] < direito[i]){
                pares += esquerdo[i];
            } else {
                pares += direito[i];
            }
        }
        printf("%d\n", pares);
    }

    return 0;
}