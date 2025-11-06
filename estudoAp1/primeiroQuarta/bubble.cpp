#include <iostream>
#include <stdio.h>

using namespace std;

void bubble(int tamamho, int v[]) {
    for (int i = 0; i < tamamho - 1; i++) {
        for (int j = 0; j < tamamho - i - 1; j++) {
            if (v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}


int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};

    int tamanho = sizeof(v)/sizeof(v[0]);

    bubble(tamanho, v);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;

    }
    return 0;
}