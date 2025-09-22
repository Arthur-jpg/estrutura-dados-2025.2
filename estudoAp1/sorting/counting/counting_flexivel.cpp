#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    // Encontrar o valor máximo para determinar o tamanho do array de contagem
    int maxVal = *max_element(arr, arr + n);
    
    // Criar array de contagem dinamicamente
    int* contagem = new int[maxVal + 1]();  // Inicializa com zeros
    
    // Contar ocorrências
    for (int i = 0; i < n; i++) {
        contagem[arr[i]]++;
    }
    
    // Reconstruir array ordenado
    int posicao = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (contagem[i] > 0) {
            arr[posicao] = i;
            posicao++;
            contagem[i]--;
        }
    }
    
    // Liberar memória
    delete[] contagem;
}

int main() {
    int n;
    cout << "Digite o tamanho do array: ";
    cin >> n;
    
    // Criar array dinamicamente
    int* arr = new int[n];
    
    cout << "Digite os elementos do array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Array original: ";
    imprimir(arr, n);
    
    countingSort(arr, n);
    
    cout << "Array ordenado: ";
    imprimir(arr, n);
    
    // Liberar memória
    delete[] arr;
    
    return 0;
}