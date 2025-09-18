#include <iostream>
#include <string>
using namespace std;

int inverterNumero(int intdonumero) {
    int numero = intdonumero;
    int resultado = 0;
    int multiplicador = 1;
    
    while (numero > 0) {
        int digito = numero % 10;
        resultado = resultado + (digito * multiplicador);
        multiplicador = multiplicador * 10;
        numero = numero / 10;
    }
    
    return resultado;
}

int main() {
    cout << "7000 invertido: " << inverterNumero(7000) << endl;
    cout << "8000 invertido: " << inverterNumero(8000) << endl;
    cout << "51 invertido: " << inverterNumero(51) << endl;
    
    int a = inverterNumero(7000);
    int b = inverterNumero(8000);
    int c = inverterNumero(51);
    
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << "Esperado: " << c << endl;
    cout << "Resultado: " << (a + b == c ? "True" : "False") << endl;
    
    return 0;
}
