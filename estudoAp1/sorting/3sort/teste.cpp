#include <iostream>
#include <stdio.h>

using namespace std;


void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}
void selection(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        
        int indexMin = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[indexMin]) {
                    indexMin = j;
                    
            }
        }
        int aux;
        aux = v[indexMin];
        v[indexMin] = v[i];
        v[i] = aux;


    }

    imprimir(v,n);
}

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++){
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    imprimir(v,n);
}

void bubblesort(int v[], int n){

    for (int i = 0; i < (n - 1); i++) {
        for(int j = 0; j < (n - i - 1); j++) {
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

    imprimir(v, n);
}

int main() {
    int v[10] = {3, -1, 2, 5, 12, 7, 5, 4, 9, -3};

    cout << "Selection --------------" << endl;
    selection(v, 10);
    cout << "Insertion --------------" << endl;
    insertionSort(v, 10);
    cout << "Bubble --------------" << endl;
    bubblesort(v, 10);



    return 0;
}