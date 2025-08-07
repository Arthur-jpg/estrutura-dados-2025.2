#include <stdio.h>
#include <iostream>

using namespace std;

int fatorial(int x) {
    if (x == 0){
        return 1;
    }
    return x * fatorial(x-1);
} 

int main() {

    cout << fatorial(5) << endl;

    return 0;
}