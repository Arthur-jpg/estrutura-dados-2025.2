#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// 1. Implementação Recursiva Simples - Complexidade: Tempo O(2^n), Espaço O(n)
long long fibonacciRecursivoSimples(int n) {
    // Casos base
    if (n <= 1) {
        return n;
    }
    // Caso recursivo - INEFICIENTE: recalcula os mesmos valores
    return fibonacciRecursivoSimples(n - 1) + fibonacciRecursivoSimples(n - 2);
}

// 2. Implementação Iterativa - Complexidade: Tempo O(n), Espaço O(1)
long long fibonacciIterativo(int n) {
    if (n <= 1) {
        return n;
    }
    
    long long anterior = 0;    // F(0)
    long long atual = 1;       // F(1)
    long long proximo;
    
    // Calcula de F(2) até F(n)
    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;  // F(i) = F(i-1) + F(i-2)
        anterior = atual;            // Atualiza para próxima iteração
        atual = proximo;
    }
    
    return atual;
}

// 3. Implementação Recursiva com Memoização - Complexidade: Tempo O(n), Espaço O(n)
vector<long long> memo;

long long fibonacciMemoizacao(int n) {
    // Verifica se já foi calculado
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Casos base
    if (n <= 1) {
        memo[n] = n;
        return n;
    }
    
    // Calcula e armazena o resultado
    memo[n] = fibonacciMemoizacao(n - 1) + fibonacciMemoizacao(n - 2);
    return memo[n];
}

// Função para testar performance
void testarPerformance(int n) {
    cout << "\n=== TESTE DE PERFORMANCE PARA F(" << n << ") ===" << endl;
    
    // Teste Iterativo
    auto inicio = chrono::high_resolution_clock::now();
    long long resultado1 = fibonacciIterativo(n);
    auto fim = chrono::high_resolution_clock::now();
    auto duracao1 = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Iterativo: " << resultado1 << " - Tempo: " << duracao1.count() << " microsegundos" << endl;
    
    // Teste Memoização
    memo.assign(n + 1, -1);  // Reinicializa memo
    inicio = chrono::high_resolution_clock::now();
    long long resultado2 = fibonacciMemoizacao(n);
    fim = chrono::high_resolution_clock::now();
    auto duracao2 = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Memoização: " << resultado2 << " - Tempo: " << duracao2.count() << " microsegundos" << endl;
    
    // Teste Recursivo Simples (apenas para valores pequenos)
    if (n <= 35) {  // Evita espera muito longa
        inicio = chrono::high_resolution_clock::now();
        long long resultado3 = fibonacciRecursivoSimples(n);
        fim = chrono::high_resolution_clock::now();
        auto duracao3 = chrono::duration_cast<chrono::microseconds>(fim - inicio);
        cout << "Recursivo Simples: " << resultado3 << " - Tempo: " << duracao3.count() << " microsegundos" << endl;
    } else {
        cout << "Recursivo Simples: [Muito lento para n=" << n << ", pulando teste]" << endl;
    }
}

int main() {
    int numero;
    
    cout << "Digite um número para calcular Fibonacci: ";
    cin >> numero;
    
    // Validação de entrada
    if (numero < 0) {
        cout << "Fibonacci não definido para números negativos!" << endl;
        return 1;
    }
    
    // Inicializa memo para memoização
    memo.assign(numero + 1, -1);
    
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "F(" << numero << ") = " << fibonacciIterativo(numero) << endl;
    
    // Testes de performance
    cout << "\n=== COMPARAÇÃO DE PERFORMANCE ===" << endl;
    
    // Teste com números pequenos
    if (numero <= 35) {
        testarPerformance(numero);
    }
    
    // Sempre testa com alguns valores específicos
    cout << "\nComparações adicionais:" << endl;
    testarPerformance(20);
    testarPerformance(30);
    
    if (numero > 35) {
        cout << "\nPara F(" << numero << "):" << endl;
        cout << "Resultado: " << fibonacciIterativo(numero) << endl;
        cout << "Nota: Recursivo simples seria extremamente lento para este valor!" << endl;
    }
    
    return 0;
}