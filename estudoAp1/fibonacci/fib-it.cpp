#include <iostream>
#include <stdio.h>

using namespace std;

int numeros_fib[1000];

void fibo_it(int x) {
    for (int i = 2; i <= x; i++) {
        numeros_fib[i] = numeros_fib[i-1] + numeros_fib[i-2];
    }

} 

void inicilizar() {

    numeros_fib[0] = 0;
    numeros_fib[1] = 1;

}


int main() {

    int entrada;

    cin >> entrada;

    inicilizar();
    fibo_it(entrada);

    int resulado = numeros_fib[entrada];

    cout << resulado << endl;



    return 0;
}