#include <iostream>
#include <stdio.h>

using namespace std;

// int particao(int esquerda, int direita, int v[]) {
//     int pivot = v[direita];
//     int varControle = esquerda - 1; 
//     for (int i = esquerda; i < direita; i++){
//         if (v[i] < pivot) {
//             varControle++;
//             int aux = v[i];
//             v[i] = v[varControle];
//             v[varControle] = aux;
//         }
//     }
//     int aux = v[direita];
//     v[direita] = v[varControle + 1];
//     v[varControle + 1] = aux;

//     return varControle + 1;
// }


// void quickMain(int esquerda, int direita, int v[]) {

//     if (esquerda < direita) {
//         int particaos = particao(esquerda, direita, v);
//         quickMain(esquerda, particaos - 1, v);
//         quickMain(particaos + 1, direita, v);

//     }


// }




int particao(int esquerda, int direita, int v[]) {
    int pivot = v[direita];
    int varAux = esquerda - 1;
    for (int i = esquerda; i < direita; i++) {
        if (v[i] < pivot) {
            varAux++;
            int aux = v[i];
            v[i] = v[varAux];
            v[varAux] = aux;
        }
    }
    int aux = v[direita];
    v[direita] = v[varAux + 1];
    v[varAux + 1] = aux;
    return varAux + 1;
}


void quickMain(int esquerda, int direita, int v[]) {
    if (esquerda < direita) {
        int particaos = particao(esquerda, direita, v);
        quickMain(esquerda, particaos - 1, v);
        quickMain(particaos + 1, direita, v);
    }
}

int main() {
    int v[10] = {8,3,50,69,54,6,7,80,65,10 };
    int tamanho = sizeof(v)/sizeof(v[0]);

    quickMain(0, tamanho-1, v);

    for (int i = 0; i < tamanho; i++){
        cout << v[i] << endl;
    }
    return 0;
}