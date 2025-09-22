#include <iostream>
#include <stdio.h>

using namespace std;

int v[1000];

void fat_it(int x) {
    v[0] = 1;
    v[1] = 1;
    
    for (int i = 2; i <= x; i++){
        v[i] = i * v[i-1];
    }
}


int main() {
    for (int i = 0; i < 1000; i++) {
        v[i] = -1;
    }

    fat_it(5);
    cout << v[5] << endl;

}