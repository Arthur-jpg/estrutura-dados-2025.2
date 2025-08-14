#include <iostream>
#include <stdio.h>

using namespace std;

int fib_recursivo(int x){
    if (x == 0) {
        return 1;
    } else if (x == 1) {
        return 1;
    }
    return fib_recursivo(x-1) + fib_recursivo(x-2);

}


int fib_vetor(int x) {
    int fib[1000];
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i <= x; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        
    }
    return fib[x];


    


}


int main() {

    printf("%d\n",fib_recursivo(10));
    printf("%d\n",fib_vetor(10));
    
    return 0;
}