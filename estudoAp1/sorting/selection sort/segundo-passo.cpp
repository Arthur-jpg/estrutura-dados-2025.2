#include <iostream>
#include <stdio.h>

using namespace std;



int main() {
    int lista[7] = {2, 5, 3, 6, 0, 1, 12};

    int indexMin = 0;
    int indexMin2 = 1;

    if (lista[indexMin2] < lista[indexMin]) swap(indexMin, indexMin2);


    for (int i = 2; i < 7; i++){
        if (lista[i] < lista[indexMin]) {
            indexMin2 = indexMin;
            indexMin = i;
        } else if ( lista[i] < lista[indexMin2]) {
            indexMin2 = i;
        }
    }

    int aux1, aux2;
    aux1 = lista[0];
    lista[0] = lista[indexMin];
    lista[indexMin] = aux1;

    aux2 = lista[1];
    lista[1] = lista[indexMin2];
    lista[indexMin2] = aux2;


    for (int j = 0; j<7; j++) {
        cout << lista[j] << endl;
    }



    return 0;
}