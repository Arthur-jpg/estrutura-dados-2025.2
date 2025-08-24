#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int numeroTestes;

    while (true) {
        cin >> numeroTestes;
        if (numeroTestes == 0){
            break;
        }

        int numeros[numeroTestes];
        for (int i = 0; i < numeroTestes; i++) {
            cin >> numeros[i];
        }
        
        int maior = -1;
        int posMaior = -1;
        
        for (int i = 0; i < numeroTestes; i++) {
            if (numeros[i] > maior) {
                maior = numeros[i];
                posMaior = i;
            }
        }
        
        int segundoMaior = -1;
        int posSegundoMaior = -1;
        
        for (int i = 0; i < numeroTestes; i++) {
            if (i != posMaior && numeros[i] > segundoMaior) {
                segundoMaior = numeros[i];
                posSegundoMaior = i;
            }
        }
        printf("%d\n", posSegundoMaior + 1);
    }

    return 0;
}