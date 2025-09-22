#include <iostream>
#include <stdio.h>

using namespace std;

int v[10] = {2, 4, 5, 6, 8, 9, 10, 12, 87, 90};

void bubble(int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++){
            if (v[j] > v[j+1]) {
                int aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    bubble(tamanho);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
}