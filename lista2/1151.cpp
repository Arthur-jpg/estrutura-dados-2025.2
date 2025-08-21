#include <iostream>
#include <stdio.h>

using namespace std;

int fibonacci [46];

void fibo(int N) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i <= N; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}



int main() {
    int entrada;
    cin >> entrada;
    fibo(entrada);
    for (int i = 0; i < entrada - 1; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("%d\n", fibonacci[entrada-1]);
}

