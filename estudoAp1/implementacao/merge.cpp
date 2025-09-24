#include <iostream>
#include <stdio.h>

using namespace std;

// void merge(int esquerda, int meio, int direta, int v[]) {
//     int arrayAux[10] = {0};
//     int i = esquerda;
//     int j = meio + 1;
//     int varAux = esquerda;
//     while (i <= meio && j <= direta) {
//         if (v[i] < v[j]) {
//             arrayAux[varAux] = v[i];
//             i++;
//             varAux++;
//         } else if (v[i] > v[j]) {
//             arrayAux[varAux] = v[j];
//             j++;
//             varAux++;
//         }
//     }

//     while (i <= meio) {
//         arrayAux[varAux] = v[i];
//         i++;
//         varAux++;
//     }

//     while (j <= direta){
//         arrayAux[varAux] = v[j];
//         j++;
//         varAux++;
//     }

//     for (int k = esquerda; k <= direta; k++) {
//         v[k] = arrayAux[k];
//     }
// }

// void mergeMain(int esquerda, int direita, int v[]) {
//     if (esquerda < direita) {
//         int meio = (esquerda + direita) / 2;
//         mergeMain(esquerda, meio, v);
//         mergeMain(meio + 1, direita, v);
//         merge(esquerda, meio, direita, v);

//     }
// }


void merges(int esquerda, int meio, int direita, int v[]) {
    int arrAux[1000];
    int i = esquerda;
    int j = meio + 1;
    int varAux = esquerda;
    while (i <= meio && j <= direita) {
        if (v[i] < v[j]) {
            arrAux[varAux] = v[i];
            i++;
            varAux++;
        } else if (v[i] > v[j]) {
            arrAux[varAux] = v[j];
            j++;
            varAux++;
        }
    }

    while (i <= meio) {
        arrAux[varAux] = v[i];
        i++;
        varAux++;
    }

    while (j <= direita) {
        arrAux[varAux] = v[j];
        j++;
        varAux++;
    }


    for (int z = esquerda; z <= direita; z++){
        v[z] = arrAux[z];
    }
}


void mergeMain(int esquerda, int direita, int v[]) {
    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        mergeMain(esquerda, meio, v);
        mergeMain(meio + 1, direita, v);
        merges(esquerda, meio, direita, v);
    }
}


int main() {
    int v[10] = {8,3,50,69,54,6,7,80,65,10 };
    int tamanho = sizeof(v)/sizeof(v[0]);

    mergeMain(0, tamanho, v);

    for (int i = 0; i < tamanho; i++){
        cout << v[i] << endl;
    }
    return 0;
}