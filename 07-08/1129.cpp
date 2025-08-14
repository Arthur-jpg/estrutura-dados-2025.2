#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        int valores[5] = {a,b,c,d,e};
        int media = (a + b + c + d + e) / 5;
        int contagemMenores = 0;
        int posicaoMarcada = 0;
        for(int z = 0; z < 5; z++) {
            if(valores[z] < media) {
                contagemMenores++;
            } 
            if (valores[z] <= 127){
                posicaoMarcada = z;
            }
            
        }
        if (contagemMenores > 1) {
                printf("*\n");
        } else if (posicaoMarcada == 0) {
            printf("A\n");
        } else if (posicaoMarcada == 1) {
            printf("B\n");
        } else if (posicaoMarcada == 2) {
            printf("C\n");
        } else if (posicaoMarcada == 3) {
            printf("D\n");
        } else if (posicaoMarcada == 4) {
            printf("E\n");
        }
        
    }
    return 0;
}