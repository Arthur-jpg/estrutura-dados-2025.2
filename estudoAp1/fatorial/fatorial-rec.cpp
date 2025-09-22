#include <stdio.h>
#include <iostream>

using namespace std;

int fatorial(int numero) {
    if (numero <= 1) {
        return 1;
    }

    return numero * fatorial(numero-1);

}


int main() {

    int entrada;
    cin >> entrada;

    int resultado = fatorial(entrada);

    cout << resultado << endl;

    return 0;
}