#include <iostream>
#include <stdio.h>

using namespace std;

void somarMatrizes(int a[][100], int b[][100], int c[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];  // Soma elementos correspondentes
        }
    }
}

void multiplicarMatrizes(int a[][100], int b[][100], int c[][100], int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = 0;  // Inicializa com 0
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];  // SOMA os produtos
            }
        }
    }
}

void imprimirMatriz(int matriz[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;  // Tamanho das matrizes
    
    // Matriz A
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Matriz B
    int b[100][100] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    // Matrizes resultado
    int soma[100][100];
    int produto[100][100];
    
    cout << "Matriz A:" << endl;
    imprimirMatriz(a, n);
    
    cout << "\nMatriz B:" << endl;
    imprimirMatriz(b, n);
    
    // Teste da soma de matrizes
    somarMatrizes(a, b, soma, n);
    cout << "\nSoma (A + B):" << endl;
    imprimirMatriz(soma, n);
    
    // Teste da multiplicação de matrizes
    multiplicarMatrizes(a, b, produto, n);
    cout << "\nProduto (A x B):" << endl;
    imprimirMatriz(produto, n);
    
    return 0;
}