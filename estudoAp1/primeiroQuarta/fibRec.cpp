#include <iostream>
#include <stdio.h>

using namespace std;


int fib_rec(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}


int main() {
    int x;
    cin >> x;
    int resultado = fib_rec(x);
    cout << resultado << endl;
    return 0;
}