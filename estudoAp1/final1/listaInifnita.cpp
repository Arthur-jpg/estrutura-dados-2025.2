#include <iostream>
#include <stdio.h>

using namespace std;

int v[10] = {2, 4, 5, 6, 8, 9, 10, 12, 87, 90};

int buscaBinaria(int esquerda, int direita, int procurando) {
    while (esquerda < direita) {
        int meio =  (esquerda + direita) / 2;
        if (v[meio] == procurando) {
            return meio;
        }
        if (v[meio] < procurando){
            esquerda = meio + 1;
        } else if (v[meio] > procurando) {
            direita = meio - 1;
        }
    }
    return -1;
}

int buscaBinariaInfinita(int procurando) {

    if ( v[0] == procurando) {
        return 0;
    }

    int i = 1;
    while (v[i] < procurando) {
        i *= 2;
    }

    return buscaBinaria(0, i, procurando);

}



int main() {
    // como a lista é infinita eu preciso fazer log n para achar o valor e deppois uma busca binária, já que vou ter os limites

    int procurado = 10;

    int indexProcuado = buscaBinariaInfinita(procurado);

    cout << v[indexProcuado] << endl;
}