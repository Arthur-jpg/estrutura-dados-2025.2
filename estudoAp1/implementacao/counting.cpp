// #include <iostream>
// #include <stdio.h>

// using namespace std;


// void countingSort (int v[], int tamanho) {
//     int arrayAux[1000] = {0};

//     for (int i = 0; i < tamanho; i++) {
//         if (v[i] >= 0) {
//             arrayAux[v[i]]++;
//         }
//     }

//     int posicao = 0;
//     int tamanhoPercorrer = 1000;

//     for (int j = 0; j < tamanhoPercorrer; j++){
//         if (arrayAux[j] > 0) {
//             int ocorrencias = arrayAux[j];
//             while (ocorrencias > 0) {
//                 v[posicao] = j;
//                 posicao++;
//                 ocorrencias--; 
//             }
//         }
//     }
// }



#include <iostream>
#include <stdio.h>

using namespace std;


void countingSort(int v[] , int n) {

    int arrAux[100] = {0};

    for (int i = 0; i < n; i++) {
        if (v[i] >= 0) {
            arrAux[v[i]]++;
        }
    }

    int posicao = 0;
    for (int j = 0; j < 100; j++) {
        if (arrAux[j] > 0) {
            int contagem = arrAux[j];
            while (contagem > 0) {
                v[posicao] = j;
                posicao++;
                contagem--;
            }
        }
    } 



}



int main() {
    int v[10] = {8,3,50,69,54,6,7,80,65,10 };
    int tamanho = sizeof(v)/sizeof(v[0]);

    countingSort(v, tamanho);

    for (int i = 0; i < tamanho; i++){
        cout << v[i] << endl;
    }
}