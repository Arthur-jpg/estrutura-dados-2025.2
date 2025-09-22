#include <iostream>
#include <stdio.h>

using namespace std;

int v[8] = {4, 8, 0, 80, 65, 17, 30, 2};


void countingSort(int tamanho){
    // objetivo, contar ocorrencias
    int aux[10000]= {0};

    for (int i = 0; i < tamanho; i++){
        if (v[i] >= 0) {
            aux[v[i]]++;
        }
    }

    int posicao = 0;
    for (int j = 0; j < 10000; j++) {
        if (aux[j] > 0) {
            int quantidade = aux[j];
            for (int z = 0; z < quantidade; z++) {
                v[posicao] = j;
                posicao++;
            }
        }
    }

}


int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    countingSort(tamanho);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
    

}