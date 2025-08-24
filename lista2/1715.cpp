#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int players;
    int matches;

    cin >> players >> matches;

    int contagem = 0; 
    
    for (int i = 0; i < players; i++){
        int golss[matches];
        int contagemInterna = 0; 
        
        for (int n = 0; n < matches; n++) {
            int gol;
            cin >> gol;
            golss[n] = gol;
            
            if (gol > 0) {
                contagemInterna++; 
            }
        }
        
        if (contagemInterna == matches) {
            contagem++;
        }
    }

    printf("%d\n", contagem);

    return 0;
}