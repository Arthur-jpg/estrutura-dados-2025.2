#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    
    string entrada;

    while(getline(cin, entrada)) {
        if (entrada == "*") {
            break;
        }
        char letra = 0;
        bool dentroDeUmaPalavra = false;
        char primeirasLetras[100];
        int numeroDePalavras = 0;
        for(int i = 0; i < entrada.length(); i++){
            if(entrada[i] != ' ') {
                if(!dentroDeUmaPalavra) {
                    letra = entrada[i];
                    if (letra >= 'A' && letra <= 'Z') {
                        letra = letra + 32; 
                    }
                    primeirasLetras[numeroDePalavras] = letra;
                    numeroDePalavras++;
                    dentroDeUmaPalavra = true;
                    
                }


            } else {
                dentroDeUmaPalavra = false;
            }
        }
        bool tutograma = false;
        for(int i = 1; i < numeroDePalavras; i++) {
            if (primeirasLetras[i] != primeirasLetras[0]){
                tutograma = false;
                break;
            } else {
                tutograma = true;
            }
        }

        if (tutograma) {
            printf("Y\n");
        } else {
            printf("N\n");
        }

    }


    return 0;
}