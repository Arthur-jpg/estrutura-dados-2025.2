#include <iostream>
#include <stdio.h>

using namespace std;

void selection(int tamanho, int v[]) {

    for (int i = 0; i < tamanho; i++) {
        int indexMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if ( v[j] < v[i]) {
                indexMenor = j;
            }
        }
        int aux = v[indexMenor];
        v[indexMenor] = v[i];
        v[i] = aux;
    }
}


int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};

    int tamanho = sizeof(v)/sizeof(v[0]);

    selection(tamanho, v);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;

    }
    return 0;
}