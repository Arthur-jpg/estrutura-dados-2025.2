#include <iostream>
#include <stdio.h>

using namespace std;


// para uma matriz n*m  e outra m*p
void multi(int n, int m, int p, int c[][100], int a[][100], int b[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // Exemplo: Multiplicar matriz 2x3 por matriz 3x2
    int n = 2, m = 3, p = 2;
    
    // Matriz A (2x3)
    int a[100][100] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // Matriz B (3x2)
    int b[100][100] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    // Matriz resultado C (2x2)
    int c[100][100];
    
    // Multiplicar as matrizes
    multi(n, m, p, c, a, b);
    
    // Exibir matriz A
    cout << "Matriz A (" << n << "x" << m << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Exibir matriz B
    cout << "Matriz B (" << m << "x" << p << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Exibir matriz resultado C
    cout << "Matriz C = A × B (" << n << "x" << p << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}