#include <iostream>
#include <stdio.h>

using namespace std;

long long int F [10000];

long long int fibo(int x) {
    if (F[x] != -1) {
        return F[x];
    }
    if (x <= 1){
        F[x] = 1;
        return 1;
    }
    return F[x] = fibo(x-1) + fibo(x-2);
}


int main() {
    for(int i = 0; i < 10000; i++){
        F[i] = -1;
    }

    cout << fibo(55) << endl;
    return 0;
}