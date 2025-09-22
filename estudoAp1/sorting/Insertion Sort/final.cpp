#include <iostream>
#include <stdio.h>

using namespace std;



int main() {
    int v[7] = {5, 2, 3, 6, 0, 1, 12};

    for (int i = 1; i < 7; i++){
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }

    for (int j = 0; j<7; j++) {
        cout << v[j] << endl;
    }



    return 0;
}