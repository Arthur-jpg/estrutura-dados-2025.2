#include <iostream>
#include <vector>
using namespace std;

void counting(int v[], int tamanho, int maior) {
    vector<int> auxArray(maior + 1, 0);

    for (int i = 0; i < tamanho; i++) {
        auxArray[v[i]]++;
    }

    int posicao = 0;
    for (int i = 0; i <= maior; i++) {
        int contagem = auxArray[i];
        if ( contagem > 0) {
            while (contagem > 0) {
                v[posicao] = i;
                posicao++;
                contagem--;
            }
            
        }
    }
}

int main() {
    int v[7] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(v) / sizeof(v[0]);
    int maior = v[0];
    for (int j = 1; j < tamanho; j++) {
        if (v[j] > maior) {
            maior = v[j];
        }
    }

    counting(v, tamanho, maior);
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
