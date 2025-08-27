#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    string entrada;
    
    getline(cin, entrada); // Use getline para ler a linha completa com espaços
    
    double tempos[3]; // Array para armazenar os 3 tempos
    int indice = 0;
    string numero = "";
    
    // Percorre cada caractere da string
    for(int i = 0; i <= entrada.length(); i++) {
        // Se encontrou espaço ou chegou ao fim da string
        if(i == entrada.length() || entrada[i] == ' ') {
            if(numero != "") {
                // Converte string para double manualmente
                double valor = 0;
                double decimal = 0;
                bool temPonto = false;
                int casasDecimais = 0;
                
                for(int j = 0; j < numero.length(); j++) {
                    if(numero[j] == '.') {
                        temPonto = true;
                    } else if(!temPonto) {
                        valor = valor * 10 + (numero[j] - '0');
                    } else {
                        decimal = decimal * 10 + (numero[j] - '0');
                        casasDecimais++;
                    }
                }
                
                // Ajusta as casas decimais
                for(int k = 0; k < casasDecimais; k++) {
                    decimal = decimal / 10;
                }
                
                tempos[indice] = valor + decimal;
                indice++;
                numero = ""; // Reset para o próximo número
            }
        } else if(entrada[i] != ' ') {
            numero += entrada[i]; // Adiciona caractere ao número atual
        }
    }
    
    // Encontra o menor tempo
    double menorTempo = tempos[0];
    int vencedor = 0;
    bool empate = false;
    
    for(int i = 1; i < 3; i++) {
        if(tempos[i] < menorTempo) {
            menorTempo = tempos[i];
            vencedor = i;
            empate = false;
        } else if(tempos[i] == menorTempo) {
            empate = true;
        }
    }
    
    // Verifica se há empate
    if(empate) {
        cout << "Empate" << endl;
    } else {
        if(vencedor == 0) cout << "Otavio" << endl;
        else if(vencedor == 1) cout << "Bruno" << endl;
        else cout << "Ian" << endl;
    }
    
    return 0;
}