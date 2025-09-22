#include <iostream>
#include <stdio.h>

using namespace std;

// basicamente, vamos fazer o esquema de trocar os números comparando cada um com todos, mas para todos eles e um de cada vez

int main() {
    int lista[7] = {2, 5, 3, 6, 0, 1, 12};

    for (int i = 0; i < 6; i++) {
        
        int indexMin = i;

        for (int j = i + 1; j < 7; j++) {
            if (lista[j] < lista[indexMin]) {
                indexMin = j;
                
            }
        }
        int aux;
        aux = lista[indexMin];
        lista[indexMin] = lista[i];
        lista[i] = aux;


    }


    for (int j = 0; j<7; j++) {
        cout << lista[j] << endl;
    }



    return 0;
}