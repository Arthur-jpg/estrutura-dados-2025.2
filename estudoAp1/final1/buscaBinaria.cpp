#include <iostream>
#include <stdio.h>

using namespace std;

int v[10] = {2, 4, 5, 6, 8, 9, 10, 12, 87, 90};

int buscaBinaria(int esquerda, int direita, int procurado) {

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (v[meio] == procurado) {
            return meio;
        }

        if (v[meio] < procurado) {
            esquerda = meio + 1;
        } else if ( v[meio] > procurado) {
            direita = meio - 1;
        }

    }

    return -1;
}




int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);

    int procurado = 10;

    int indexProcuado = buscaBinaria(0, tamanho - 1, procurado);

    cout << v[indexProcuado] << endl;

}