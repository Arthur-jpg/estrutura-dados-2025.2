#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int distance;
    float fuel_spent;

    cin >> distance >> fuel_spent;

    float consumo = distance/fuel_spent;

    printf("%.3f km/l\n", consumo);

    return 0;
}