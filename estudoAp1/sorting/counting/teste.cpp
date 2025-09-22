#include <stdio.h>
#include <iostream>
using namespace std;
int v[8] = {3, 2, 5, 12, 7, 5, 4, 9};
int vContagem[1000];
int arrayOrdenada[8];

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}

void counting (int n) {

    for (int i = 0; i < n; i++) {
        int valor = v[i];
        if (valor >= 0) {
            vContagem[valor]++;
        }
    }

    int posicao = 0;
    for (int j = 0; j < 1000; j++) {
        if (vContagem[j] > 0) {
            int quantidade = vContagem[j];
            for (int aux = 0; aux < quantidade; aux++) {
                arrayOrdenada[posicao] = j;  // j é o valor, não a quantidade
                posicao++;
            }
        }
    }
}


int main() {

    counting(8);
    imprimir(arrayOrdenada, 8);



    return 0;
}
