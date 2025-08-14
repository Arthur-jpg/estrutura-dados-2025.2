#include <iostream>
#include <stdio.h>

using namespace std;


int fibo(int x) {
    if (x <= 1){
        return 1;
    }
    return fibo(x-1) + fibo(x-2);
}


int main() {

    cout << fibo(55) << endl;
    return 0;
}