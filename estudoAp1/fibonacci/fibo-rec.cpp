#include <iostream>
#include <stdio.h>

using namespace std;

int fibo_rec(int x) {

    if (x == 0) {
        return 0;
    }
    
    if ( x == 1) {
        return 1;
    }

    return fibo_rec(x-1) + fibo_rec(x-2);


} 


int main() {

    int entrada;

    cin >> entrada;

    int resultado = fibo_rec(entrada);

    cout << resultado << endl;



    return 0;
}