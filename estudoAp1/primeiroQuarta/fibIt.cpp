#include <iostream>
#include <stdio.h>

using namespace std;

int fib[1000] = {0};

void fibIt(int n) {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 1000; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    int x;
    cin >> x;
    fibIt(x);
    cout << fib[x] << endl;
    return 0;
}