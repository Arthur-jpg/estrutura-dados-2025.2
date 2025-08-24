#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int entrada;

    cin >> entrada;

    if (entrada == 1) {
        printf("Top 1\n");
    } else if (entrada <= 3) {
        printf("Top 3\n");
    } else if (entrada <= 5) {
        printf("Top 5\n");
    } else if (entrada <= 10) {
        printf("Top 10\n");
    } else if (entrada <= 25) {
        printf("Top 25\n");
    } else if (entrada <= 50) {
        printf("Top 50\n");
    } else if (entrada <= 100) {
        printf("Top 100\n");
    }

    return 0;
}