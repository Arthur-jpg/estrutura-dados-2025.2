#include <iostream>
#include <stdio.h>

using namespace std;

void insertion(int tamanho, int v[]){
    for (int i = 0; i < tamanho; i++) {
        int elementoAtual = v[i];
        int posicaoAnterior = i - 1;
        while (posicaoAnterior >= 0 && v[posicaoAnterior] > elementoAtual){
            v[posicaoAnterior + 1] = v[posicaoAnterior];
            posicaoAnterior--;
        }
        v[posicaoAnterior + 1] = elementoAtual;
    }
}

int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};

    int tamanho = sizeof(v)/sizeof(v[0]);

    insertion(tamanho, v);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;

    }
    return 0;
}