#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    while (true) {

        int entrada;
        cin >> entrada;

        if (entrada == 0) {
            break;
        }
        
        int pontoInicialX, pontoInicialY;
        cin >> pontoInicialX >> pontoInicialY;
        
        for (int i = 0; i < entrada; i++) {
            int x, y;
            cin >> x >> y;
            
            if (x == pontoInicialX || y == pontoInicialY) {
                printf("divisa\n");
            } else if (x > pontoInicialX && y > pontoInicialY) {
                printf("NE\n");
            } else if (x < pontoInicialX && y > pontoInicialY) {
                printf("NO\n");
            } else if (x > pontoInicialX && y < pontoInicialY) {
                printf("SE\n");
            } else if (x < pontoInicialX && y < pontoInicialY) {
                printf("SO\n");
            }
        }
    }
    
    return 0;
}