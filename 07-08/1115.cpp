#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int inputx, inputy;
    cin >> inputx >> inputy;
    while (inputx != 0 && inputy != 0) {
        if (inputx > 0 && inputy > 0) {
            printf("primeiro\n");
        } else if (inputx > 0 && inputy < 0) {
            printf("quarto\n");
        } else if (inputx < 0 && inputy > 0) {
            printf("segundo\n");
        } else if (inputx < 0 && inputy < 0) {
            printf("terceiro\n");
        } else {
            break;
        }
        cin >> inputx >> inputy; 
    }
    return 0;
}