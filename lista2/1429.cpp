#include <stdio.h>
#include <iostream>
using namespace std;

int fatorial(int n) {
    if(n == 0){
        return 1;
    }
    return n * fatorial(n-1);
    
}

int main() {

    int number;

    while(true) {
        cin >> number;

        if (number == 0) {
            break;
        }
        int digitos[5];
        int tamanho = 0;

        while (number > 0) {
            digitos[tamanho] = number % 10;
            number /= 10;
            tamanho++;
            
        }

        int resultado = 0;

        for(int i = 0; i<tamanho;i++){
            resultado += digitos[i] * fatorial(i);
        }

        printf("%d\n", resultado);




    }
    

    return 0;
}