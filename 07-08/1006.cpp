#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float pesoA = 2;
    float pesoB = 3;
    float pesoC = 5;
    float media = (a*pesoA + b*pesoB + c*pesoC)/(pesoA + pesoB + pesoC);
    if (media < 0) {
        printf("A média é inválida 0>\n");
    } else if (media > 10) {
        printf("A média é inválida 10<\n");
    } else {
        printf("MEDIA = %.1f\n", media);
    }
    return 0;
}