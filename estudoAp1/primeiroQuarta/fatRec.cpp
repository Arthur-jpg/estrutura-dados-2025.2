#include <iostream>
#include <stdio.h>

using namespace std;

int fatrec(int n) {

    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }

    return n * fatrec(n-1);
}


int main() {
    int x;
    cin >> x;
    int resultado = fatrec(x);
    cout << resultado << endl;
    return 0;
}