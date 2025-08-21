#include <iostream>
#include <stdio.h>

using namespace std;

long long int F [10000];

void fibo(int N) {
    for(int i = 2; i <= N; i++){
        F[i] = F[i-1] + F[i-2];
    }
}


void inicializa_vertor() {
    F[0] = -1;
    F[1] = -1;
}

int main() {
    inicializa_vertor();
    fibo(10000);

    int x;
    cin >> x;
    cout << F[x]<< endl;
    return 0;
}

