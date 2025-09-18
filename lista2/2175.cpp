#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    float o, b, i;

    cin >> o >> b >> i;

    float tempos[3] = {o,b,i};
    string nomes[3] = {"Otavio","Bruno","Ian"};

    int contagemEmpate = 0;
    float menor = 1000;
    string vencedor;

    for (int i = 0; i < 3; i++) {
        if (tempos[i] < menor) {
            menor = tempos[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tempos[i] == menor) {
            contagemEmpate++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tempos[i] == menor) {
            vencedor = nomes[i];
        }
    }

    if (contagemEmpate > 1) {
        cout << "Empate" << endl;
    } else {
        cout << vencedor << endl;
    }



    
    return 0;
}