#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long long primiero, segundo;

    while(true) {

        cin >> primiero >> segundo;

        if (primiero == 0 && segundo == 0) {
            break;
        }

        long long terceiro = 2*primiero - segundo;

        printf("%lld\n", terceiro);


    }
    

    return 0;
}