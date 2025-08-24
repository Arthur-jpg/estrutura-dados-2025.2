#include <stdio.h>
#include <iostream>

using namespace std;

int fatorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * fatorial(x-1);
}

int main() {
    int entrada;
    cin >> entrada;
    
    int contador = 0;
    
    while (entrada > 0) {
        int i = 1;
        while (fatorial(i) <= entrada) {
            i++;
        }
        i--; 
        entrada -= fatorial(i);
    
        contador++;
    }
    
    printf("%d\n", contador);
    return 0;
}