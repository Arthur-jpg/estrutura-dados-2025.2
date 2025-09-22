#include <iostream>
#include <stdio.h>

using namespace std;

int fat_rec(int x) {
    if (x <= 1) {
        return 1;
    }

    return x * fat_rec(x-1);
}


int main() {

    int resultado = fat_rec(5);
    cout << resultado << endl;

}