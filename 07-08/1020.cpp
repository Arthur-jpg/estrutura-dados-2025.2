#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int entrada, anos, meses, dias;
    cin >> entrada;

    anos = entrada/365;
    meses = (entrada - (anos * 365))/30;
    dias = entrada - (anos * 365) - (meses * 30); 

    printf("%d ano(s)\n", anos);
    printf("%d mes(s)\n", meses);
    printf("%d dia(s)\n", dias);
   

    return 0;
}