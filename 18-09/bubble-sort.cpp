#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * BUBBLE SORT - Algoritmo de Ordenação
 * 
 * Funcionamento:
 * O Bubble Sort funciona como "bolhas" subindo à superfície:
 * - Compara elementos adjacentes e os troca se estiverem na ordem errada
 * - Os maiores elementos "borbulham" para o final do array
 * - A cada passada completa, o maior elemento restante vai para sua posição final
 * 
 * Exemplo com vetor [64, 34, 25, 12, 22, 11, 90]:
 * 
 * Passada 1: [34, 25, 12, 22, 11, 64, 90] - 90 vai para o final
 * Passada 2: [25, 12, 22, 11, 34, 64, 90] - 64 vai para penúltima posição  
 * Passada 3: [12, 22, 11, 25, 34, 64, 90] - 34 vai para sua posição
 * Passada 4: [12, 11, 22, 25, 34, 64, 90] - 25 vai para sua posição
 * Passada 5: [11, 12, 22, 25, 34, 64, 90] - 22 vai para sua posição
 * Passada 6: [11, 12, 22, 25, 34, 64, 90] - já ordenado!
 * 
 * Otimização: Se em uma passada não houve troca, o array já está ordenado!
 */

void bubbleSort(int arr[], int n) {
    bool trocou; // flag para otimização - detecta se houve troca na passada atual
    
    // Loop externo: controla quantas passadas serão feitas
    // Após i passadas, os i maiores elementos já estão nas posições finais corretas
    for (int i = 0; i < n - 1; i++) {
        trocou = false; // assume que não haverá trocas nesta passada
        
        // Loop interno: compara elementos adjacentes
        // Note que diminuímos o limite (n - i - 1) porque os últimos i elementos
        // já estão ordenados após i passadas
        for (int j = 0; j < n - i - 1; j++) {
            // Se elemento atual é maior que o próximo, eles estão na ordem errada
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos (swap)
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                // Marca que houve pelo menos uma troca nesta passada
                trocou = true;
            }
        }
        
        // OTIMIZAÇÃO: Se não houve nenhuma troca nesta passada,
        // significa que o array já está ordenado - podemos parar!
        if (!trocou) break;
    }
}

// Função auxiliar para imprimir o array
void imprimir_array(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Função para demonstrar o passo a passo do algoritmo
void bubbleSort_debug(int arr[], int n) {
    cout << "Array inicial: ";
    imprimir_array(arr, n);
    
    bool trocou;
    int passada = 1;
    
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        cout << "\n--- Passada " << passada << " ---" << endl;
        
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparando " << arr[j] << " e " << arr[j + 1] << ": ";
            
            if (arr[j] > arr[j + 1]) {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
                cout << "TROCA! → ";
            } else {
                cout << "OK → ";
            }
            imprimir_array(arr, n);
        }
        
        cout << "Resultado da passada " << passada << ": ";
        imprimir_array(arr, n);
        
        if (!trocou) {
            cout << "✓ Nenhuma troca foi feita - array já está ordenado!" << endl;
            break;
        }
        
        passada++;
    }
}

// Versão simples do bubble sort (sem otimização) para comparação
void bubbleSort_simples(int arr[], int n) {
    // Versão básica sem otimização - sempre faz n-1 passadas
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    cout << "=== DEMONSTRAÇÃO DO BUBBLE SORT ===" << endl;
    
    // Array de exemplo
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    // Cria uma cópia para demonstração
    int arr_copia[7];
    for (int i = 0; i < n; i++) {
        arr_copia[i] = arr[i];
    }
    
    cout << "Executando Bubble Sort com debug:" << endl;
    bubbleSort_debug(arr_copia, n);
    
    cout << "\n=== COMPARAÇÃO: VERSÕES DO BUBBLE SORT ===" << endl;
    
    // Teste com array já ordenado
    int arr_ordenado[] = {1, 2, 3, 4, 5};
    int n_ord = 5;
    
    cout << "\nTeste com array já ordenado: ";
    imprimir_array(arr_ordenado, n_ord);
    cout << "Com otimização: para imediatamente!" << endl;
    
    cout << "\nCaracterísticas do Bubble Sort:" << endl;
    cout << "✓ Estável: mantém ordem relativa de elementos iguais" << endl;
    cout << "✓ In-place: ordena no próprio array, usa O(1) espaço extra" << endl;
    cout << "✓ Adaptativo: melhor performance em arrays já ordenados (com otimização)" << endl;
    cout << "✗ Ineficiente: muitas comparações e trocas desnecessárias" << endl;
    
    cout << "\nComplexidade:" << endl;
    cout << "- Melhor caso: O(n) - array já ordenado (com otimização)" << endl;
    cout << "- Caso médio: O(n²)" << endl;
    cout << "- Pior caso: O(n²) - array em ordem reversa" << endl;
    cout << "- Espaço: O(1)" << endl;
    
    cout << "\nUso prático:" << endl;
    cout << "- Bom para: ensino, arrays muito pequenos, detectar se já está ordenado" << endl;
    cout << "- Evitar para: arrays grandes (ineficiente)" << endl;
    
    return 0;
}