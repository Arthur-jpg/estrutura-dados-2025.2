#include <iostream>
#include <stdio.h>

using namespace std;

int variavel = 0;

int fib(int n) {
    variavel++;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int numero, entrada;
    cin >> numero;
    
    for (int i = 0; i < numero; i++) {
        cin >> entrada;
        variavel = 0;
        int result = fib(entrada);
        printf("fib(%d) = %d calls = %d\n", entrada, variavel-1, result);
    }
    
    return 0;
}