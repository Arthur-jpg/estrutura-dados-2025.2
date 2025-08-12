#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int entrada, horas, minutos, segundos, auxmin, auxseg;
    cin >> entrada;

    horas = entrada / 3600;
    minutos = (entrada - (3600 * horas))/60;
    segundos = entrada - (minutos * 60) - (3600*horas);


    printf("%d:%d:%d\n", horas, minutos, segundos);

   

    return 0;
}