#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * INSERTION SORT - Algoritmo de Ordenação
 * 
 * Funcionamento:
 * O Insertion Sort funciona como quando organizamos cartas na mão:
 * 1. Parte esquerda do array: elementos já ordenados
 * 2. Parte direita do array: elementos ainda não processados
 * 
 * A cada iteração:
 * - Pega o próximo elemento da parte não ordenada
 * - Insere este elemento na posição correta da parte ordenada
 * - Move os elementos maiores uma posição para a direita
 * 
 * Exemplo com vetor [5, 2, 4, 6, 1, 3]:
 * 
 * Inicial: [5, 2, 4, 6, 1, 3]  (5 já está "ordenado")
 * i=1: Insere 2 → [2, 5, 4, 6, 1, 3]  (move 5 para direita)
 * i=2: Insere 4 → [2, 4, 5, 6, 1, 3]  (move 5 para direita)
 * i=3: Insere 6 → [2, 4, 5, 6, 1, 3]  (6 já está no lugar certo)
 * i=4: Insere 1 → [1, 2, 4, 5, 6, 3]  (move todos para direita)
 * i=5: Insere 3 → [1, 2, 3, 4, 5, 6]  (move 4,5,6 para direita)
 */

void insertion_sort(int vetor[], int n) {
    // Começa do índice 1 porque consideramos que o primeiro elemento (índice 0)
    // já está "ordenado" por si só (um elemento sozinho sempre está ordenado)
    for (int i = 1; i < n; i++) {

        // Guarda o elemento atual que será inserido na posição correta
        int atual = vetor[i];
        
        // j aponta para o último elemento da parte já ordenada
        // (fronteira entre parte ordenada e não ordenada)
        int j = i - 1;
        
        // Move elementos da parte ordenada uma posição para a direita
        // enquanto eles forem maiores que o elemento atual
        // Isso abre espaço para inserir o elemento atual na posição correta
        while (j >= 0 && vetor[j] > atual) {
            vetor[j + 1] = vetor[j];  // move elemento uma posição para direita
            j = j - 1;                // volta uma posição para continuar comparando
        }
        
        // Quando sai do while, j+1 é a posição correta para inserir o elemento atual
        // Todos os elementos maiores já foram movidos para a direita
        vetor[j + 1] = atual;
    }
    
    // Após todas as iterações, todo o array estará ordenado
}

// Função auxiliar para imprimir o array
void imprimir_array(int vetor[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Função para demonstrar o passo a passo do algoritmo
void insertion_sort_debug(int vetor[], int n) {
    cout << "Passo 0 (inicial): ";
    imprimir_array(vetor, n);
    
    for (int i = 1; i < n; i++) {
        int atual = vetor[i];
        int j = i - 1;
        
        cout << "Passo " << i << ": Inserindo " << atual << " na posição correta" << endl;
        
        while (j >= 0 && vetor[j] > atual) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = atual;
        
        cout << "Resultado: ";
        imprimir_array(vetor, n);
    }
}

int main() {
    cout << "=== DEMONSTRAÇÃO DO INSERTION SORT ===" << endl;
    
    // Array de exemplo
    int vetor[] = {5, 2, 4, 6, 1, 3};
    int n = 6;
    
    cout << "Executando Insertion Sort com debug:" << endl;
    insertion_sort_debug(vetor, n);
    
    cout << "\nCaracterísticas do Insertion Sort:" << endl;
    cout << "✓ Estável: mantém ordem relativa de elementos iguais" << endl;
    cout << "✓ In-place: ordena no próprio array, usa O(1) espaço extra" << endl;
    cout << "✓ Adaptativo: é mais eficiente em arrays já parcialmente ordenados" << endl;
    cout << "✓ Online: pode ordenar uma lista conforme recebe os elementos" << endl;
    
    cout << "\nComplexidade:" << endl;
    cout << "- Melhor caso: O(n) - array já ordenado" << endl;
    cout << "- Caso médio: O(n²)" << endl;
    cout << "- Pior caso: O(n²) - array ordenado em ordem reversa" << endl;
    cout << "- Espaço: O(1)" << endl;
    
    return 0;
}