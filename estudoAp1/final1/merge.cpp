#include <iostream>
#include <stdio.h>

using namespace std;

int v[8] = {4, 8, 0, 80, 65, 17, 30, 2};

void merge(int esquerda, int meio, int direita) {
    int auxs[8];
    int i = esquerda;
    int j = meio + 1;
    int aux = esquerda;

    while (i <= meio && j <= direita) {
        if (v[i] < v[j]) {
            auxs[aux] = v[i];
            i++;
            aux++;
        } else {
            auxs[aux] = v[j];
            j++;
            aux++;
        }
    }

    while (i <= meio) {
        auxs[aux] = v[i];
        i++;
        aux++;
    }

    while (j <= direita) {
        auxs[aux] = v[j];
        j++;
        aux++;
    }

    for (int k = esquerda; k <= direita; k++) {
        v[k] = auxs[k];
    }



}


void mergeSort(int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        mergeSort(esquerda, meio);
        mergeSort(meio + 1, direita);
        merge(esquerda, meio, direita);

    }
}

int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    mergeSort(0,tamanho-1);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
    

}