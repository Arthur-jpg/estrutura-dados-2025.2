#include <stdio.h>
#include <iostream>
using namespace std;

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << endl;
    }
    
}
// ----------------------

void selectionSort(int v[], int n) {
    
    for (int i = 0; i < n; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        int aux = v[i];
        v[i] = v[minIndex];
        v[minIndex] = aux;
    }
    
    
}

// ----------------------

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int key = v[i]; // vai começar do 1
        int j = i - 1; // vai começar do zero
        while (v[j] >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;

        }
        v[j+1] = key;
    }
}


// ----------------------

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}





// ----------------------


void countingSort(int v[], int n) {
    
    int arrAux[1000];
    int arrResultado[n];

    // Inicializar array auxiliar com zeros
    for (int i = 0; i < 1000; i++) {
        arrAux[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int valor = v[i];
        arrAux[valor]++;
    }

    int indiceResultado = 0;
    for (int j = 0; j < 1000; j++) {
        if (arrAux[j] > 0){
            int qtdNumero = arrAux[j];
            for (int z = 0; z < qtdNumero; z++){
                v[indiceResultado] = j;
                indiceResultado++;
            }
        }
    }
    
}




// -------------------------------------


int particao(int low, int high, int v[]) {

    int pivot = v[high];
    int variavelControle = low - 1;

    for (int i = low; i < high; i++){
        if (v[i] < pivot) {
            variavelControle++;
            int aux = v[i];
            v[i] = v[variavelControle];
            v[variavelControle] = aux;
        }

    }
    // swap pivot
    int aux = v[variavelControle + 1];
    v[variavelControle + 1] = v[high];
    v[high] = aux;

    return variavelControle + 1;
}

void quick(int low, int high, int v[]) {

    if ( low < high) {
        int part = particao(low, high, v);
        quick(low, part - 1, v);
        quick(part + 1, high, v);
    }
}

void quickSortMain(int v[], int n) {
    int low = 0;
    int high = n - 1;
    quick(low, high, v);
}

// -------------------------------------


void merge(int low, int mid, int high, int n, int v[]) {
    int arrTemporaria[n];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (v[i] < v[j]) {
            arrTemporaria[k] = v[i];
            i++;
            k++;
        } else {
            arrTemporaria[k] = v[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        arrTemporaria[k] = v[i];
        i++;
        k++;
    }

    while (j <= high) {
        arrTemporaria[k] = v[j];
        j++;
        k++;
    }

    for (int z = low; z <= high; z++){
        v[z] = arrTemporaria[z];
    }

    
}


void mergeSort(int low, int high, int v[], int n) {

    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid, v, n);
        mergeSort(mid + 1, high, v, n);
        merge(low, mid, high, n, v);
    }
}


void mergeSortMain(int v[], int n) {
    int low = 0;
    int high = n - 1;
    mergeSort(low, high, v, n);
}





int main() {
    int v[10] = {3, 1, 2, 5, 12, 7, 5, 4, 9, 3};

    
    /*
    Selection sort: vamos comparar o primeiro elemento com todos os outros e guardar o menor, depois trocar eles de lugar
    e seguir fazendo isso (sempre guardando o index do menor número)
    Lembrando que a comparação é do indice J para o indice do menorIndex
    Só temos a varivael menor index para poder fazer a troca depois fora do for mais interno
    */
    cout << "Selection --------------" << endl;
    selectionSort(v, 10);
    imprimir(v, 10);
    
    /*
    Insertion sort: vai sempre comparar com o maior e trocar. Insere cada elemento na posição correta do subarray ordenado.
    Então quando o proximo elemento chegar ele vai comparara com todos da subarray e colocar no lugar certo, para isso que serve o while
    O for prinicpal vai começar com 1 para que o ponteiro j comece no i - 1 para começar do zero. Além disso temos uma key = v[i]
    */
    cout << "Insertion --------------" << endl;
    insertionSort(v, 10);
    imprimir(v, 10);


    
    /*
    bubbleSort: o bubble sort basicamente é um if dentro do if onde a gnt compara se o atual é maior do que próximo
    Se for troca. Fazendo isso pegando um número e comparando com todos os outros e fazendo isso n vezes
    lembrando i < n -1 e j < n - i - 1
    */
    cout << "Bubble --------------" << endl;
    bubbleSort(v, 10);
    imprimir(v, 10);
    


    /*
    Counting sort: vamos contar a quantidade de ocorrencias de um elemento e depois exibilo se sua contagem for 
    maior que zero. Como a posição representa o número, colocamos na array a posição que já é o número 
    Precisamos contar quantas repetições aquele número tem.
    */
    cout << "Counting Sort --------------" << endl;
    countingSort(v, 10);
    imprimir(v, 10);


    /*
    Quick Sort:     
    
    if ( low < high) {
        int part = particao(low, high, v);
        quick(low, part - 1, v);
        quick(part + 1, high, v);
    }

    a parte de particao tem a ideia de pivot e variavel de controle sendo -1. Quando entramos no loop é necessário
    conferir se o elemento está antes do pivot ou não, se tiver antes trocamos com o na primeira posição na array (
    por isso tem a questão de começar no -1 para a variavel de controle). Quando terminamos trocamos o pivot para a
    posição dele que é 1 depois da variavel de controle e retornamos ele (variavel de controle + 1).
    */
    cout << "Quick --------------" << endl;
    quickSortMain(v, 10);
    imprimir(v, 10);
    
    
    /*
    Merge sort:
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid, v, n);
        mergeSort(mid + 1, high, v, n);
        merge(low, mid, high, n, v);
        }
    }

    A ideia é ir dividindo o lado esquerdo até ficar com array unitaria low < high, depois fazer o mesmo com o direito
    No merge vamos precisar de uma array temporaria e mais 3 variaveis para conseguir fazer o merge
    i sendo o low, j sendo o mid + 1 (ser onde começa a direita) e o K para index da nova array
    só vamos comparando, se o elemento da esquerda for menor que o da direita coloca na array
    Se for o controário coloca o da direita na array 
    Depois coloca o resto que sobrou 
    E coloca a arraytemporaraia na array principal
    */
    cout << "Merge  --------------" << endl;
    mergeSortMain(v, 10);
    imprimir(v, 10);



    return 0;
}
