#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    double entrada;
    cin >> entrada;

    int valor = (int) (entrada * 100);

    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[6] = {100, 50, 25, 10, 5, 1};

    int qtdNotas[6] = {};
    int qtdMoedas[6] = {};

    for (int i = 0; i < 6; i++) {
        qtdNotas[i] = valor / notas[i];
        valor = valor % notas[i];
    }
    for (int i = 0; i < 6; i++) {
        qtdMoedas[i] = valor / moedas[i];
        valor = valor % moedas[i];
    }
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", qtdNotas[i], notas[i]/100.0);
    }
    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", qtdMoedas[i], moedas[i]/100.0);
    }

    return 0;
}