#include <iostream>
#include <string>
using namespace std;

int inverterStringeTransformInt(string entrada) {
    string invertida = "";
    for (int i = entrada.length() - 1; i >= 0; i--) {
        invertida += entrada[i];
    }
    return stoi(invertida);
}

int main() {
    string entrada;

    while (getline(cin, entrada)) {
        if (entrada == "0+0=0") {
            cout << "True" << endl;
            break;
        }

        string a = "";
        string b = "";
        string c = "";

        int estado = 0;

        for (int i = 0; i < entrada.length(); i++) {
            char caractere = entrada[i];

            if (caractere == '+') {
                estado = 1;
            } else if (caractere == '=') {
                estado = 2;
            } else {
                if (estado == 0) {
                    a += caractere;
                } else if (estado == 1) {
                    b += caractere;
                } else if (estado == 2) {
                    c += caractere;
                }
            }
        }
        
        int resultadoA = inverterStringeTransformInt(a);
        int resultadoB = inverterStringeTransformInt(b);
        int resultadoC = inverterStringeTransformInt(c);

        if (resultadoA + resultadoB == resultadoC) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    return 0;
}