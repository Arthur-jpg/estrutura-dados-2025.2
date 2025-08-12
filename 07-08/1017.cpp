#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int tempo, avg_speed;
    float consumo = 12.00;

    cin >> tempo >> avg_speed;

    int distancia_total = tempo * avg_speed;

    float litragem = distancia_total/consumo;

    printf("%.3f\n", litragem);

    return 0;
}