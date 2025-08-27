#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int qtdVotos;

    int contagemAFacvor = 0;
    int contagemContra = 0;

    cin >> qtdVotos;


    int voto;
    for (int i = 0; i < qtdVotos; i++) {

        cin >> voto;

        if(voto == 1){
            contagemContra++;
        } else if (voto == 0) {
            contagemAFacvor++;
        }
        

    }

    if (contagemAFacvor > contagemContra) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}