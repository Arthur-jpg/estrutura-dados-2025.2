#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    float pesoA = 3.5;
    float pesoB = 7.5;
    float media = (a*pesoA + b*pesoB)/(pesoA + pesoB);
    if (media < 0) {
        printf("A média é inválida 0>\n");
    } else if (media > 10) {
        printf("A média é inválida 10<\n");
    } else {
        printf("MEDIA = %.5f\n", media);
    }
    return 0;
}