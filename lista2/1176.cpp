#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long F[61];

void fibo(int x) {
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= x; i++){
        F[i] = F[i-1] + F[i-2];
    }
}

int main() {
    fibo(60);
    
    int entrada;
    cin >> entrada;
    for(int i = 0; i < entrada; i++) {
        int x;
        cin >> x;
        cout << "Fib(" << x << ") = " << F[x] << endl;
    }
    
    return 0;
}