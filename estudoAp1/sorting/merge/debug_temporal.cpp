#include <stdio.h>
#include <iostream>
using namespace std;
int v[10] = {3, -1, 2, 5, 12, 7, 5, 4, 9, -3};
int nivel = 0;

void imprimir(int v[], int n) {
    for (int j = 0; j<n; j++) {
        cout << v[j] << " ";
    }
    cout << endl;
}

void printIndent() {
    for (int i = 0; i < nivel; i++) cout << "  ";
}

void merge(int left, int mid, int right) {
    printIndent();
    cout << "🔗 MERGE [" << left << ".." << mid << "] com [" << (mid+1) << ".." << right << "]" << endl;
    
    int temp[10];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if(v[i] <= v[j]) {
            temp[k] = v[i];
            i++;
        } else {
            temp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = v[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = v[j];
        j++;
        k++;
    }

    for (int z = left; z <= right; z++) {
        v[z] = temp[z];
    }
    
    printIndent();
    cout << "✅ Resultado: ";
    for (int idx = left; idx <= right; idx++) {
        cout << v[idx] << " ";
    }
    cout << endl;
}

void mergeSort(int low, int high) {
    printIndent();
    cout << "📊 DIVIDINDO [" << low << ".." << high << "]: ";
    for (int idx = low; idx <= high; idx++) {
        cout << v[idx] << " ";
    }
    cout << endl;
    
    if (low >= high) {
        printIndent();
        cout << "🛑 PARADA: elemento único [" << low << "]" << endl;
        return;
    }

    int mid = (high + low) / 2;
    
    printIndent();
    cout << "➡️  Indo para ESQUERDA [" << low << ".." << mid << "]" << endl;
    nivel++;
    mergeSort(low, mid);
    nivel--;
    
    printIndent();
    cout << "➡️  Indo para DIREITA [" << (mid+1) << ".." << high << "]" << endl;
    nivel++;
    mergeSort(mid + 1, high);
    nivel--;
    
    merge(low, mid, high);
}

int main() {
    cout << "🎯 ARRAY INICIAL: ";
    imprimir(v, 10);
    cout << "\n=== INÍCIO DO MERGE SORT ===" << endl;
    
    mergeSort(0, 9);
    
    cout << "\n=== RESULTADO FINAL ===" << endl;
    imprimir(v, 10);
    return 0;
}