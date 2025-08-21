// vetor dentro da main com 1 milhao
// Preencher vetor com todos os números pares
// Fazer o mesmo declarando no escopo global

#include <stdio.h>
#include <iostream>

using namespace std;

int vetorGloabal[10000000];
int main() {
    
    for (int i = 0; i <= 10000000; i++) {
        vetorGloabal[i] = i*2;
    }

    for (int i = 0; i <= 100000000; i++) {
        cout << vetorGloabal[i] << endl;
    }


    
    return 0;


}