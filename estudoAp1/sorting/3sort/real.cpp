#include <stdio.h>
#include <iostream>
using namespace std;

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}

// o selection é o que compara o numero atual com todos os outros e troca com o menor
// em seguida, comparar o segundo com todos os outros e troar o menor e ir indo
// o int min tem que ser dinamico respeitando o I
void selection(int v[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int menorIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menorIndex]) {
                menorIndex = j;
            }
        }
        int aux = v[i];
        v[i] = v[menorIndex];
        v[menorIndex] = aux;
    }

    imprimir(v, n);

}

// enquanto o anteriror for maior que o proximo ele troca se não passa para o outro
// ele difere do bubble pq o bule troca se for menor. Esse não, ele troca se for menor e compara com o resto que já foi trocado
// exatamente o que o while faz
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i ++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;
    }

    imprimir(v, n);


}


// compra uma dupla, se for menor, troca, se não continua até o final
void bubbleSort (int v[], int n) {

    for ( int i = 0; i < (n-1); i++){
        for (int j = 0; j < (n - i - 1); j++) {
            if (v[j] > v[j + 1]) {
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
    bubbleSort(v, 10);



    return 0;
}
