#include <iostream>
#include <stdio.h>

using namespace std;


int fibIt(int n) {

    int resultado = 1;

    for (int i = 2; i <= n; i++){
        resultado *= i ;
    }
    return resultado;
}


int main() {
    int x;
    cin >> x;
    int resultado = fibIt(x);
    cout << resultado << endl;
    return 0;
}