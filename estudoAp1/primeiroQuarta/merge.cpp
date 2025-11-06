#include <iostream>
#include <vector>
using namespace std;

void merge(int esquerda, int meio, int direita, int v[]) {

    vector<int> auxArray(direita - esquerda + 1, 0);
    int i = esquerda;
    int j = meio + 1;
    int posicion = esquerda;

    while (i <= meio && j <= direita) {
        if (v[i] < v[j]){
            auxArray[posicion] = v[i];
            i++;
            posicion++;
        } else if ( v[i] > v[j]) {
            auxArray[posicion] = v[j];
            j++;
            posicion++;
        }
    }

    while (i <= meio) {
        auxArray[posicion] = v[i];
        i++;
        posicion++;
    }
    while (j <= direita) {
        auxArray[posicion] = v[j];
        j++;
        posicion++;
    }

    for(int z = esquerda; z <= direita; z++) {
        v[z] = auxArray[z];
    }
    
}

void mergeSort(int esquerda, int direita, int v[]){
    if ( esquerda < direita){
        int meio = (esquerda + direita) / 2;
        mergeSort(esquerda, meio, v);
        mergeSort(meio + 1, direita, v);
        merge(esquerda, meio, direita, v);
    }
}

int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(v) / sizeof(v[0]);


    mergeSort(0, tamanho-1, v);


    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
