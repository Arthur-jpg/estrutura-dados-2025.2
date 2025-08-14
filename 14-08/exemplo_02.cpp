#include <iostream>
#include <stdio.h>

using namespace std;


// Complexidade muito maior
// int fat[10000];
// int fatorial(int x){
//     if(fat[x] != -1) {
//         return fat[x];
//     }
//     if (x == 0) {
//         return 1;
//     }
//     return fat[x] = x*fatorial(x-1);
// }



// dynamic programmig
int main() {
    int fat[10], N; // declaração de vetor
    cin >> N;
    fat[0] = 1;
    for (int i = 1; i< N; i ++){
        fat[i] = fat[i-1]*i;
    } 
    for (int i = 0; i<N; i++) {
        cout << "fat["<< i <<"] = " << fat[i] << endl;
    }



    return 0;
}