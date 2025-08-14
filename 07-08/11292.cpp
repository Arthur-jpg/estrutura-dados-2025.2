#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        for(int i = 0; i < n; i++) {
            int valores[5];
            for(int j = 0; j < 5; j++) {
                cin >> valores[j];
            }
            int marcados = 0;
            int posicaoMarcada = -1;
            for(int z = 0; z < 5; z++) {
                if(valores[z] <= 127) {
                    marcados++;
                    posicaoMarcada = z;
                }
            }
            if (marcados == 1) {
                printf("%c\n", 'A' + posicaoMarcada);
            } else {
                printf("*\n");
            }
        }
    }
    return 0;
}