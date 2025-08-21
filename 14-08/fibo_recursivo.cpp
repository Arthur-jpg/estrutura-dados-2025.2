#include <iostream>
#include <stdio.h>

using namespace std;

int variavel[100] = {0};

int fibo(int x) {
    if (x <= 1){
        return 1;
    }
    variavel[0]++;
    return fibo(x-1) + fibo(x-2);
}


int main() {

    cout << fibo(5-1) << endl;
    cout << variavel[0] << endl;
    return 0;
}