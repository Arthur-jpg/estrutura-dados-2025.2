#include <stdio.h>
#include <iostream>

using namespace std;

long long fatoriais[1000000];
int calculado[1000000];

void calcular(int x) {
    if (calculado[0] == -1) {
        fatoriais[0] = 1;
        fatoriais[1] = 1;
        calculado[0] = 1;
        calculado[1] = 1;
    }

    for (int i = 2; i <= x; i++) {
        if (calculado[i] == -1) {
            fatoriais[i] = fatoriais[i-1] * i;
            calculado[i] = 1;
        }
    }
}

int main() {
    for (int i = 0; i <= 1000000; i ++) {
        calculado[i] = -1;
    }

    int entrada;
    int contador = 0;
    char resultado;
    
    while (cin >> entrada) {
        contador++;
        calcular(entrada);

        long long resultadoFatorial = fatoriais[entrada];

        string fatorialString = to_string(resultadoFatorial);
        for (int i = fatorialString.length() - 1; i >= 0; i--) {
            if (fatorialString[i] != '0') {
                resultado = fatorialString[i];
                break;
            }
        }
        
        printf("Instancia %d\n", contador);
        printf("%c\n", resultado);
    }
    
    return 0;

}



