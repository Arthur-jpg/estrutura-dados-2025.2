#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int numeros[101] = {0};
    int entrada;
    for (int i = 0; i < 4; i++) {
        cin >> entrada;
        numeros[i] = entrada; 
    }

    int maiorNumero = numeros[0];
    int posicao;
    for(int i = 1; i <= 100; i++) {
        if (maiorNumero < numeros[i]){
            maiorNumero = numeros[i];
            posicao = i;
        }
    }
    printf("%d\n", maiorNumero);
    printf("%d\n", posicao + 1);

    return 0;
}