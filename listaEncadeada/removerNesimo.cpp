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

    void removerNesimoDoFim(int n) {
        No *p1 = this->head;
        No *p2 = this->head;

        // move p2 n+1 posições à frente (para manter a diferença)
        for (int i = 0; i <= n; i++) {
            if (p2 == nullptr) {
                cout << "Erro: a lista tem menos de " << n << " elementos." << endl;
                return;
            }
            p2 = p2->proximo;
        }

        // avança os dois ponteiros até p2 chegar ao fim
        while (p2 != nullptr) {
            p1 = p1->proximo;
            p2 = p2->proximo;
        }

        // agora p1->proximo é o nó que deve ser removido
        No *remover = p1->proximo;
        if (remover != nullptr) {
            p1->proximo = remover->proximo;
            delete remover;
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

    cout << "Lista original: ";
    lista.imprimir(); // 10 20 30 40 50

    int n = 1;
    lista.removerNesimoDoFim(n);

    cout << "Lista após remover o " << n << "º elemento a partir do final: ";
    lista.imprimir(); // 10 20 30 50

    return 0;
}
