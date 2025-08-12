#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int maiorAB = (a + b + abs(a-b))/2;
    int maiorXC = (maiorAB + c + abs(maiorAB-c))/2;
    printf("%d eh o maior\n", maiorXC);


    return 0;
}