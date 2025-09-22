#include <stdio.h>
#include <iostream>
using namespace std;
int v[10] = {3, -1, 2, 5, 12, 7, 5, 4, 9, -3};

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}

// percorrer a esquerda e a direita juntos e colocar na esquerda se for menor e na direita se for maior

void merge(int left, int mid, int right) {
    int temp[10];
    int i = left;
    int j = mid + 1;
    int k = left;  // Índice para o array temporário

    // Comparar e mesclar elementos das duas metades
    while (i <= mid && j <= right) {
        if(v[i] <= v[j]) {
            temp[k] = v[i];
            i++;
        } else {
            temp[k] = v[j];
            j++;
        }
        k++;
    }

    // Copiar elementos restantes da metade esquerda
    while (i <= mid) {
        temp[k] = v[i];
        i++;
        k++;
    }

    // Copiar elementos restantes da metade direita
    while (j <= right) {
        temp[k] = v[j];
        j++;
        k++;
    }

    // Copiar elementos do array temporário de volta para o array original
    for (int z = left; z <= right; z++) {
        v[z] = temp[z];
    }
}

void mergeSort(int low, int high) {
    if (low < high) {
        
            int mid = (high + low) / 2;
        
            mergeSort(low, mid);
            mergeSort(mid + 1, high);
            merge(low, mid, high);
        }

    }





int main() {

    mergeSort(0, 9);
    imprimir(v, 10);



    return 0;
}
