#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int qtd;
    cin >> qtd;
    int frequencia[2001] = {0};

    for(int i = 0; i < qtd; i++) {
        int entrada;
        cin >> entrada;
        frequencia[entrada]++;
    }

    for (int i = 0; i <= 2000; i++) {
        if(frequencia[i] > 0) {
            printf("%d aparece %d vez(es)\n", i, frequencia[i]);
        }
    }

    return 0;
}