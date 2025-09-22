#include <iostream>
#include <stdio.h>

using namespace std;

int resutlados[100];

void fib_iterativa(int x) {
    resutlados[0] = 0;
    resutlados[1] = 1;

    for (int i = 2; i < x + 1; i++) {
        resutlados[i] = resutlados[i-1] + resutlados[i-2];
    }
}


int main() {

    for (int i = 0; i < 100; i++) {
        resutlados[i] = -1;
    }
    fib_iterativa(8);
    cout << resutlados[6] << endl;


}