#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    
    int x = -1;
    for (int i = 0; i <= 4; i++) {
        x += 2;
        cout << "I=" << x <<" J=7" << endl;
        cout << "I=" << x <<" J=6" << endl;
        cout << "I=" << x <<" J=5" << endl;
    }
    return 0;
}