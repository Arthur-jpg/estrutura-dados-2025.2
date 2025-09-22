#include <iostream>
#include <stdio.h>

using namespace std;

int v[8] = {4, 8, 0, 80, 65, 17, 30, 2};


void insertionSort(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int key = v[i];
        int controle = i - 1;
        while (controle >= 0 && v[controle] > key) {
            v[controle + 1] = v[controle];
            controle--;
        }
        v[controle+1] = key;

    }
}


int main() {
    int tamanho = sizeof(v)/sizeof(v[0]);
    insertionSort(tamanho);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << endl;
    }
    

}