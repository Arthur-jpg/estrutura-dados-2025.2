#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * SELECTION SORT - Algoritmo de Ordenação
 * 
 * Funcionamento:
 * O Selection Sort funciona dividindo o array em duas partes:
 * 1. Parte ordenada (inicialmente vazia)
 * 2. Parte não ordenada (inicialmente todo o array)
 * 
 * A cada iteração:
 * - Encontra o MENOR elemento da parte não ordenada
 * - Troca este elemento com o primeiro elemento da parte não ordenada
 * - Move a fronteira entre as partes uma posição para a direita
 * 
 * Exemplo com vetor [64, 25, 12, 22, 11]:
 * 
 * Inicial: [64, 25, 12, 22, 11]
 * Passo 1: Encontra menor (11) e troca com posição 0 → [11, 25, 12, 22, 64]
 * Passo 2: Encontra menor (12) e troca com posição 1 → [11, 12, 25, 22, 64]
 * Passo 3: Encontra menor (22) e troca com posição 2 → [11, 12, 22, 25, 64]
 * Passo 4: Encontra menor (25) e troca com posição 3 → [11, 12, 22, 25, 64]
 * Final:   [11, 12, 22, 25, 64] ✓
 */

void selection_sort(int n, int vetor[]) {
    // Loop externo: percorre cada posição do array que precisa ser preenchida
    // com o próximo menor elemento
    for (int i = 0; i < n; i++) {
        // Assume que o elemento atual (posição i) é o menor
        int menor = vetor[i];
        int pos = i; // guarda a posição do menor elemento encontrado
        
        // Loop interno: procura o menor elemento na parte não ordenada
        // (de i+1 até o final do array)
        for (int j = i + 1; j < n; j++) {
            // Se encontrou um elemento menor que o atual "menor"
            if (vetor[j] < menor) {
                menor = vetor[j]; // atualiza o valor do menor
                pos = j;          // atualiza a posição do menor
            }
        }
        
        // Troca o elemento da posição i com o menor elemento encontrado
        // Isso coloca o menor elemento na posição correta (ordenada)
        int aux = vetor[i];      // salva o valor da posição i
        vetor[i] = vetor[pos];   // coloca o menor na posição i
        vetor[pos] = aux;        // coloca o valor original de i na posição do menor
    }
    
    // Após todas as iterações, o array estará completamente ordenado
}

// Função auxiliar para imprimir o array
void imprimir_array(int n, int vetor[]) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Exemplo prático do Selection Sort
    cout << "=== DEMONSTRAÇÃO DO SELECTION SORT ===" << endl;
    
    // Array de exemplo
    int vetor[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    cout << "Array inicial: ";
    imprimir_array(n, vetor);
    
    cout << "\nExecutando Selection Sort..." << endl;
    selection_sort(n, vetor);
    
    cout << "Array ordenado: ";
    imprimir_array(n, vetor);
    
    cout << "\nComplexidade:" << endl;
    cout << "- Tempo: O(n²) - sempre, pois sempre percorre todo o array" << endl;
    cout << "- Espaço: O(1) - ordena in-place, usa apenas variáveis auxiliares" << endl;
    
    return 0;
}