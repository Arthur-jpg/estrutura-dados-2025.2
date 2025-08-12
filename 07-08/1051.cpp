#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float entrada;
    float i8 = 0, i18 = 0, i28 = 0, resultado = 0;
    cin >> entrada;

    if (entrada > 4500.00) {
        i28 = (entrada - 4500.00) * 0.28;
        i18 = (4500.00 - 3000.00) * 0.18;
        i8 = (3000.00 - 2000.00) * 0.08;
    } else if (entrada > 3000.00) {
        i18 = (entrada - 3000.00) * 0.18;
        i8 = (3000.00 - 2000.00) * 0.08;
    } else if (entrada > 2000.00) {
        i8 = (entrada - 2000.00) * 0.08;
    }

    resultado = i8 + i18 + i28;

    if (resultado > 0){
        printf("R$ %.2f\n", resultado);
    } else {
        printf("Isento\n");
    }

    return 0;
}