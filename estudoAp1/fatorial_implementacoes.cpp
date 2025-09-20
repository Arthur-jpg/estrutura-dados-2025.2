#include <iostream>
using namespace std;

// Implementação Recursiva - Complexidade: Tempo O(n), Espaço O(n)
long long fatorialRecursivo(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    // Caso recursivo
    return n * fatorialRecursivo(n - 1);
}

// Implementação Iterativa - Complexidade: Tempo O(n), Espaço O(1)
long long fatorialIterativo(int n) {
    long long resultado = 1;
    
    // Loop de 2 até n
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    
    return resultado;
}

int main() {
    int numero;
    
    cout << "Digite um número para calcular o fatorial: ";
    cin >> numero;
    
    // Validação de entrada
    if (numero < 0) {
        cout << "Fatorial não definido para números negativos!" << endl;
        return 1;
    }
    
    // Calculando e exibindo resultados
    cout << "\nResultados:" << endl;
    cout << numero << "! (recursivo) = " << fatorialRecursivo(numero) << endl;
    cout << numero << "! (iterativo) = " << fatorialIterativo(numero) << endl;
    
    return 0;
}