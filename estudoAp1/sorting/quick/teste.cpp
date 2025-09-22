#include <stdio.h>
#include <iostream>
using namespace std;
int v[10] = {3, -1, 2, 5, 12, 7, 5, 4, 9, -3};

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}

// Escolhe um pivot e coloca os elementos menores a esquerda do pivot
// e os elementos maiores na direita do pivot
// o pivot vai estar na posição certa 

int particao(int low, int high) {

    int pivot = v[high];
    int controle = low - 1;

    for (int i = low; i < high; i++) {
        if (v[i] < pivot) {
            controle++;
            // swap (v[controle], v[i])
            int aux = v[i];
            v[i] = v[controle];
            v[controle] = aux;

        }
        
    }
    // swap(v[i + 1], v[high])
    int aux = v[high];
    v[high] = v[controle+1];
    v[controle+1] = aux;

    return controle + 1;


}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = particao(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}





int main() {

    quickSort(0, 9);
    imprimir(v, 10);



    return 0;
}
