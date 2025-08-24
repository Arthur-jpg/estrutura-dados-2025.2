// Não fiz

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Função para reverter os dígitos de um número representado como string
string reverseDigits(string number) {
    // Remove zeros à esquerda depois da reversão (que eram zeros à direita)
    string reversed = number;
    reverse(reversed.begin(), reversed.end());
    
    // Remove zeros à esquerda (que eram zeros à direita no número original)
    while (reversed.size() > 1 && reversed[0] == '0') {
        reversed.erase(0, 1);
    }
    
    return reversed;
}

// Função para converter string para inteiro
int stringToInt(const string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 10 + (c - '0');
    }
    return result;
}

int main() {
    string equation;
    
    while (getline(cin, equation)) {
        if (equation == "0+0=0") {
            cout << "True" << endl;
            break;
        }
        
        // Encontrar as posições de '+' e '='
        size_t plus_pos = equation.find('+');
        size_t equals_pos = equation.find('=');
        
        // Extrair os três números
        string a_str = equation.substr(0, plus_pos);
        string b_str = equation.substr(plus_pos + 1, equals_pos - plus_pos - 1);
        string c_str = equation.substr(equals_pos + 1);
        
        // Reverter os dígitos de cada número
        string reversed_a = reverseDigits(a_str);
        string reversed_b = reverseDigits(b_str);
        string reversed_c = reverseDigits(c_str);
        
        // Converter para inteiros
        int a = stringToInt(reversed_a);
        int b = stringToInt(reversed_b);
        int c = stringToInt(reversed_c);
        
        // Verificar se a equação é verdadeira
        if (a + b == c) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    
    return 0;
}