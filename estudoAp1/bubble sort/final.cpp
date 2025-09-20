#include <iostream>
#include <stdio.h>

using namespace std;



int main() {
    int v[7] = {2, 5, 3, 6, 0, 1, 12};

    for (int i = 0; i < (7 - 1); i++) {
        for(int j = 0; j < (7 - i - 1); j++) {
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

    for (int j = 0; j<7; j++) {
        cout << v[j] << endl;
    }


    return 0;
}