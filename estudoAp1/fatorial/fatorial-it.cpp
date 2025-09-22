#include <iostream>
#include <stdio.h>

using namespace std;

int fatorais[1000];

void calcularFatoriais(int x) {
    for (int i = 2; i <= x; i++) {
        fatorais[i] = i * fatorais[i-1];
    }
}



void inicializar_fatoriais() {

    fatorais[0] = 1;
    fatorais[1] = 1;
}


int main() {

    int entrada;
    cin >> entrada;

    inicializar_fatoriais();
    calcularFatoriais(entrada);

    int resultado = fatorais[entrada];

    cout << resultado << endl;



    return 0;
}