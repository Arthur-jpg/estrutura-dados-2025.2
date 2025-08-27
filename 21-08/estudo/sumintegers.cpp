#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n; // 3

    for (int i = 0; i < n; i++){ // 0, 1, 2
        for (int j = i + 1; j < n; j++) { // (1, 2), (2) 
            cout << i + j << endl; 
        }
    }

    return 0;
}