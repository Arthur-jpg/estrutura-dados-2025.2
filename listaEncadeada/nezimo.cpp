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

    int encontrarNesimoDoFim(int n) {
        No *p1 = this->head->proximo;
        No *p2 = this->head->proximo;

        // move p2 n posições à frente
        for (int i = 0; i < n; i++) {
            if (p2 == nullptr) {
                cout << "Erro: a lista tem menos de " << n << " elementos." << endl;
                return -1;
            }
            p2 = p2->proximo;
        }

        // avança p1 e p2 juntos até p2 chegar ao fim
        while (p2 != nullptr) {
            p1 = p1->proximo;
            p2 = p2->proximo;
        }

        if (p1 != nullptr)
            return p1->dado;
        else {
            cout << "Lista vazia." << endl;
            return -1;
        }
    }
};

int main() {
    ListaEncadeada lista;

    lista.addFim(10);
    lista.addFim(20);
    lista.addFim(30);
    lista.addFim(40);
    lista.addFim(50);

    cout << "Lista: ";
    lista.imprimir(); // 10 20 30 40 50

    int n = 1;
    cout << "O " << n << "º elemento a partir do final é: " << lista.encontrarNesimoDoFim(n) << endl;
    // Saída esperada: 40

    return 0;
}
