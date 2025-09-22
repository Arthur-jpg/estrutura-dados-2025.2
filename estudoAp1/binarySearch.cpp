#include <iostream>
#include <stdio.h>

using namespace std;

// binary search vai retornar o indice do elemento que queremos para depois imprimir
int v[5] = {2, 4, 6, 8, 10};

int binarySearch(int esquerda, int direita, int numero) {
    while (esquerda <= direita) {
        int mid = (esquerda + direita) / 2;

        if (v[mid] == numero) return mid;

        if (v[mid] < numero) {
            esquerda = mid + 1;
        }
        
        if (v[mid] > numero) {
            direita = mid - 1;
        }
    }

    return -1;
}

int main() {

    int indiceDoElemento = binarySearch(0, 4, 6);
    cout << indiceDoElemento << endl;
    int resultado = v[indiceDoElemento];
    cout << resultado << endl;

}