#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int entrada;
    int sequencia[100] = {0};
    int i = 0;
    while(i < 100) {
        cin >> entrada;
        if (entrada == 0) {
            break;
        }
        sequencia[i] = entrada;
        i++;
    }


    int maior = 0;
    for (int n = 0; n < 100; n++){
        if (sequencia[n] > maior) {
            maior = sequencia[n];
        }
    }
    printf("%d\n", maior);

    return 0;
}
