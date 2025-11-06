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

    void addFim(int info) {
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

    void duplicarLista() {
        No *p = this->head->proximo;

        while (p != nullptr) {
            No *duplicado = new No(p->dado); // cria nó com mesmo valor
            duplicado->proximo = p->proximo; // liga o duplicado ao próximo original
            p->proximo = duplicado;          // liga o original ao duplicado

            p = duplicado->proximo;          // avança para o próximo nó original
        }
    }
};

int main() {
    ListaEncadeada lista;

    lista.addFim(10);
    lista.addFim(20);
    lista.addFim(30);

    cout << "Lista original: ";
    lista.imprimir(); // 10 20 30

    lista.duplicarLista();

    cout << "Lista duplicada: ";
    lista.imprimir(); // 10 10 20 20 30 30

    return 0;
}
