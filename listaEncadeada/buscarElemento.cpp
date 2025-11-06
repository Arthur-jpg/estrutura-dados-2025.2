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

        while (p->proximo != nullptr) {
            p = p->proximo;
        }

        p->proximo = novo;
    }

    bool buscarElemento(int info) {
        No *p = this->head->proximo; // começa após o nó cabeça

        while (p != nullptr) {
            if (p->dado == info) {
                return true; // encontrou
            }
            p = p->proximo;
        }

        return false; // não encontrou
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

    cout << "Buscar 20: " << (lista.buscarElemento(20) ? "true" : "false") << endl;
    cout << "Buscar 40: " << (lista.buscarElemento(40) ? "true" : "false") << endl;

    return 0;
}
