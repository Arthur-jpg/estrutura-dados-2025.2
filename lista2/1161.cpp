#include <stdio.h>
#include <iostream>

using namespace std;

long long fatoriais[20];

void calcular() {
    fatoriais[0] = 1;
    fatoriais[1] = 1;

    for (int i = 2; i <= 20; i++) {
        fatoriais[i] = fatoriais[i-1] * i;
    }
}



int main() {
    calcular();
    
    int entrada1, entrada2;
    while (cin >> entrada1 >> entrada2) {

        long long fatorial1 = fatoriais[entrada1];
        long long fatorial2 = fatoriais[entrada2];
        

        cout << fatorial1 + fatorial2 << endl;
        
    }
    

    return 0;

}



