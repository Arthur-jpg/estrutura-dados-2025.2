// #include <iostream>
// #include <stdio.h>

// using namespace std;

// int main() {

//     int fibonot[9] = {4, 6, 7, 9, 10, 11, 12, 14, 15};

//     int entrada;

//     cin >> entrada;
    
//     cout << fibonot[entrada-1] << endl;
    

//     return 0;
// }


#include <iostream>
#include <stdio.h>

using namespace std;

long long int F[100000];

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

bool eFibonacci(int num) {
    for (int i = 0; i < 100000; i++) { 
        long long fib_atual = fibo(i);
        if (fib_atual == num) {
            return true;
        }
        if (fib_atual > num) {
            return false;
        }
    }
    return false;
}
int main() {
    for(int i = 0; i < 100000; i++){
        F[i] = -1;
    }
    
    int entrada;
    cin >> entrada;
    
    int contador = 0;
    int numero = 1;
    
    while (contador < entrada) {
        if (!eFibonacci(numero)) {
            contador++;
            if (contador == entrada) {
                cout << numero << endl;
                break;
            }
        }
        numero++;
    }
    
    return 0;
}