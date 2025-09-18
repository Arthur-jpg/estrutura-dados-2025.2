#include <iostream>
#include <stdio.h>

using namespace std;

long long numerosFibo[100000];

long long int fibo (int x) {
    if (numerosFibo[x] != -1) {
        return numerosFibo[x];
    }
    if (x <= 1) {
        return 1;
    }

    return numerosFibo[x] = fibo(x-1) + fibo(x-2);

}

bool efibo(int x) {
    for (int i = 0; i < 100000; i++) {
        long long resultado = fibo(i);
        if (resultado == x) {
            return true;
        }
        if (resultado > x) {
            return false;
        }

    }
    return false;
}


int main() {
    for(int i = 0; i < 100000; i++){
        numerosFibo[i] = -1;
    }
    int entrada;
    cin >> entrada;

    int contador = 0;
    int numero = 1;

    while (contador < entrada){
        if (!efibo(numero)){
            contador++;
            if (entrada == contador){
                cout << numero << endl;
                break;
            }
        }
        numero++;
    }

    return 0;
}