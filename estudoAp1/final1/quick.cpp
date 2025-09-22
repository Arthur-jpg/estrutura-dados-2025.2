#include <iostream>
#include <stdio.h>

using namespace std;

int v[8] = {4, 8, 0, 80, 65, 17, 30, 2};

int particao(int esquerda, int direita) {
    int pivot = v[direita];
    int varControle = esquerda - 1;
    for (int i = esquerda; i < direita; i++){
        if (v[i] < pivot) {
            varControle++;
            int aux = v[i];
            v[i] = v[varControle];
            v[varControle] = aux;
        }
    }

    int aux = v[direita];
    v[direita] = v[varControle + 1];
    v[varControle + 1] = aux;
    return varControle + 1;
}


void quickSort(int esquerda, int direita) {
    if (esquerda < direita) {
        int partica = particao(esquerda, direita);
        quickSort(esquerda, partica - 1);
        quickSort(partica + 1, direita);
    }

}


int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    quickSort(0,tamanho-1);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
    

}