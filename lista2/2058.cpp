#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int numeroLados;

    cin >> numeroLados;

    int diagonais = numeroLados - 3;

    int qtdTriangulos = diagonais + 1;

    printf("%d\n", qtdTriangulos);

    return 0;
}