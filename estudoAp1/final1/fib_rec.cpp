#include <iostream>
#include <stdio.h>

using namespace std;

int fib_rec(int x) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
     

    return fib_rec(x -1) + fib_rec(x-2);
}

int main() {

    int resultado = fib_rec(6);
    cout << resultado << endl;

}