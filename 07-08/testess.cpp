#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float entrada, resultado = 0;
    cin >> entrada;

    if (entrada > 4500.00) {
        resultado += (entrada - 4500.00) * 0.28;
        entrada = 4500.00;
    }
    if (entrada > 3000.00) {
        resultado += (entrada - 3000.00) * 0.18;
        entrada = 3000.00;
    }
    if (entrada > 2000.00) {
        resultado += (entrada - 2000.00) * 0.08;
    }

    if (resultado > 0){
        printf("R$ %.2f\n", resultado);
    } else {
        printf("Isento\n");
    }

    return 0;
}