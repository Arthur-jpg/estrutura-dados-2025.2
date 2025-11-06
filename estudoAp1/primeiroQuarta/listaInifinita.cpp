#include <iostream>
#include <stdio.h>

using namespace std;

int buscaBinaria(int esquerda, int direita, int v[], int elemento) {

    while (esquerda < direita) {
        int meio = (esquerda + direita) / 2;

        if ( v[meio] == elemento) {
            return meio;
        } else if ( v[meio] > elemento) {
            direita = meio + 1; 
        } else if ( v[meio] < elemento) {
            esquerda = meio + 1;
        }
    }
    return -1;

}

int achar(int elemento,int v[]) {
    if ( v[0] == elemento) {
        return 0;
    }
    int i = 1;
    while ( v[i] < elemento) {
        i *= 2;
    }

    return buscaBinaria(i/2, i, v, elemento);

}


int main() {
    int v[5] = {2, 4, 5, 9, 10};
    int indexResultado = achar(9, v);

    cout << indexResultado << endl;
    return 0;
}