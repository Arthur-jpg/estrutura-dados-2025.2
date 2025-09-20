#include <iostream>
#include <stdio.h>

using namespace std;



int main() {
    int lista[7] = {2, 5, 3, 6, 0, 1, 12};

    int indexMin = 0;

    for (int i = 1; i < 7; i++) {
        if (lista[i] < lista[indexMin]) {
            indexMin = i;
        }
    }

    int aux = lista[0];
    lista[0] = lista[indexMin];
    lista[indexMin] = aux;

    for (int j = 0; j<7; j++) {
        cout << lista[j] << endl;
    }



    return 0;
}