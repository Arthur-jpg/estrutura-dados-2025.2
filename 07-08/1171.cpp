#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int qtd, entrada;
    int freq[2001] = {0};

    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> entrada;
        freq[entrada]++;
    }

    for (int num = 0; num <= 2000; num++) {
        if (freq[num] > 0) {
            printf("%d aparece %d vez(es)\n", num, freq[num]);
        }
    }

    return 0;
    
}