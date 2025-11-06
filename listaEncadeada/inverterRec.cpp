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

    // Função recursiva auxiliar
    No* inverterRec(No* atual) {
        // Caso base: lista vazia ou nó final
        if (atual == nullptr || atual->proximo == nullptr)
            return atual;

        // Chamada recursiva até o último nó
        No* novoHead = inverterRec(atual->proximo);

        // Inverte o ponteiro do próximo nó para apontar para o atual
        atual->proximo->proximo = atual;
        atual->proximo = nullptr;

        // Retorna o novo primeiro nó (último da lista original)
        return novoHead;
    }

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

    void inverterRecursivo() {
        // Chama a função auxiliar e redefine o primeiro elemento
        this->head->proximo = inverterRec(this->head->proximo);
    }
};

int main() {
    ListaEncadeada lista;

    lista.addFim(10);
    lista.addFim(20);
    lista.addFim(30);
    lista.addFim(40);

    cout << "Lista original: ";
    lista.imprimir(); // 10 20 30 40

    lista.inverterRecursivo();

    cout << "Lista invertida recursivamente: ";
    lista.imprimir(); // 40 30 20 10

    return 0;
}
