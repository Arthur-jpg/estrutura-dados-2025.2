#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int valor;

    cin >> valor;

    int x[7] = {100, 50, 20, 10, 5, 2, 1};
    int qtd[7] = {0};

    for (int i = 0; i < 7; i++ ){
        qtd[i] = valor/x[i];
        valor = valor%x[i];
        if (valor == 0) {
            break;
        }
    }

    for (int i = 0; i < 7; i ++) {
        printf("%d nota(s) de R$ %d\n", qtd[i], x[i]);
    }

   

    return 0;
}