#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int qtdEntradas;
    double altura = 5.0;
    
    while (true) {
        cin >> qtdEntradas;
        if (qtdEntradas == 0) {
            break;
        }

        int qtdTrapezoids;
        double medida1, medida2;

        for (int i = 0; i < qtdEntradas; i++) {
            cin >> qtdTrapezoids >> medida1 >> medida2;
            double resultado = 0;
            printf("Size #%d:\n", i+1);
            resultado = qtdTrapezoids * (((medida1 + medida2)*altura)/2);
            
            printf("Ice Cream Used: %.2f cm2\n", resultado);
        }
        printf("\n");
    }

    return 0;
}