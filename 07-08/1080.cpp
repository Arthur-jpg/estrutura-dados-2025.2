#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int numeros[100] = {0};
    for (int i = 0; i < 100; i++){
        cin >> numeros[i];
    }
    int maior = numeros[0];
    int posicao = 0;
    for (int i = 1; i < 100; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            posicao = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicao + 1);


    return 0;
}