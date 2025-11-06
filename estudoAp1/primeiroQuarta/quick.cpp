#include <iostream>
#include <vector>
using namespace std;

int particao(int esquerda, int direita, int v[]){
    int pivot = v[direita];
    int varcontrole = esquerda -1;
    for (int i = esquerda; i < direita; i++) {
        if (v[i] < pivot){
            varcontrole++;
            int aux = v[i];
            v[i] = v[varcontrole];
            v[varcontrole] = aux;

        }

    }
    int aux = v[varcontrole + 1];
    v[varcontrole + 1] = v[direita];
    v[direita] = aux;

    return varcontrole + 1;

}

void quickSort(int esquerda, int direita, int v[]) {
    if ( esquerda < direita) {
        int part = particao(esquerda, direita, v);
        quickSort(esquerda, part -1, v);
        quickSort(part + 1, direita, v);
    }
}


int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(v) / sizeof(v[0]);


    quickSort(0, tamanho-1, v);


    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
