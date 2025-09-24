// #include <iostream>
// #include <stdio.h>

// using namespace std;

// int fib_rec(int x) {
//     if (x == 0) {
//         return 0;
//     }
//     if (x == 1) {
//         return 1;
//     }

//     return fib_rec(x - 1) + fib_rec(x-2);
// }

// int main() {
//     int target = 4;
//     int resultado = fib_rec(target);
//     cout << resultado << endl;
// }

#include <iostream>
#include <stdio.h>

using namespace std;



void bubblesort(int n, int v[]) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

}

int main () {
    int v[10] = {3, -1, 2, 5, 12, 7, 5, 4, 9, -3};
    int n = sizeof(v) / sizeof(v[0]);

    
    cout << "Array antes da ordenação: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    bubblesort(n, v);
    
    cout << "Array depois da ordenação: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}