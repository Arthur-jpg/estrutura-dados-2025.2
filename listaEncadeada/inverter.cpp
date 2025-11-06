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

    void imprimir() {
        No *p = this->head->proximo;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }

    void inverter() {
        No *anterior = nullptr;
        No *atual = this->head->proximo;
        No *proximo = nullptr;

        while (atual != nullptr) {
            proximo = atual->proximo;   // guarda o próximo nó
            atual->proximo = anterior;  // inverte o ponteiro
            anterior = atual;           // avança o anterior
            atual = proximo;            // avança o atual
        }

        // após o loop, 'anterior' é o novo primeiro nó da lista
        this->head->proximo = anterior;
    }
};

int main() {
    ListaEncadeada lista;

    lista.add(10);
    lista.add(20);
    lista.add(30);
    lista.add(40);
    lista.add(50);

    cout << "Lista original: ";
    lista.imprimir(); // Saída: 10 20 30 40

    lista.inverter();

    cout << "Lista invertida: ";
    lista.imprimir(); // Saída: 40 30 20 10

    return 0;
}
