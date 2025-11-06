#include <iostream>
using namespace std;

class No {
public:
    int dado;
    No *proximo;

    No(int d, No *p = nullptr) {
        this->dado = d;
        this->proximo = p;
    }
};

class ListaEncadeada {
    No *head;

public:
    ListaEncadeada() {
        this->head = new No(0); // nó cabeça
    }

    void add(int info) {
        No *novo = new No(info);
        No *p = this->head;

        // percorre até o último nó
        while (p->proximo != nullptr) {
            p = p->proximo;
        }

        // adiciona o novo no final
        p->proximo = novo;
    }

    int contarElementos() {
        int contador = 0;
        No *p = this->head->proximo; // ignora o nó cabeça

        while (p != nullptr) {
            contador++;
            p = p->proximo;
        }

        return contador;
    }

    void imprimir() {
        No *p = this->head->proximo;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }
};

int main() {
    ListaEncadeada lista;

    lista.add(10);
    lista.add(20);
    lista.add(30);

    lista.imprimir(); // Saída: 10 20 30

    cout << "Total de elementos: " << lista.contarElementos() << endl;
    // Saída: Total de elementos: 3

    return 0;
}
