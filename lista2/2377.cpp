#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int comprimentoEstrada, distanciaEntrePedagios, custoPorKm, valorPedagio;

    cin >> comprimentoEstrada >> distanciaEntrePedagios >> custoPorKm >> valorPedagio;

    int custoEstrada = comprimentoEstrada * custoPorKm;
    int qtdPedagios = comprimentoEstrada/distanciaEntrePedagios;
    int custoPedagio = qtdPedagios * valorPedagio;
    int custoTotal = custoEstrada + custoPedagio;

    cout << custoTotal << endl;

    return 0;
}
