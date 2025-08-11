#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int cod1, cod2, qtd1, qtd2;
    float price1, price2;

    cin >> cod1 >> qtd1 >> price1 >> cod2 >> qtd2 >> price2;

    float resultado = ((qtd1 * price1) + (qtd2 * price2));

    printf("VALOR A PAGAR: R$ %.2f\n", resultado);



    return 0;
}