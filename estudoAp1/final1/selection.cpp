#include <iostream>
#include <stdio.h>

using namespace std;

int v[8] = {4, 8, 0, 80, 65, 17, 30, 2};


void selectionSort(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int indexMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if ( v[j] < v[i]) {
                indexMenor = j;
            }
        }
        int aux = v[i];
        v[i] = v[indexMenor];
        v[indexMenor] = aux;
    }
}


int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    selectionSort(tamanho);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
    

}