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

    void ordenarLista() {
        No *i = this->head->proximo;

        while (i != nullptr) {
            No *min = i;
            No *j = i->proximo;

            // busca o menor elemento à frente
            while (j != nullptr) {
                if (j->dado < min->dado) {
                    min = j;
                }
                j = j->proximo;
            }

            // troca os valores

            int temp = i->dado;
            i->dado = min->dado;
            min->dado = temp;
            

            i = i->proximo;
        }
    }
};

int main() {
    ListaEncadeada lista;

    lista.addFim(40);
    lista.addFim(10);
    lista.addFim(30);
    lista.addFim(20);

    cout << "Lista original: ";
    lista.imprimir(); // 40 10 30 20

    lista.ordenarLista();

    cout << "Lista ordenada: ";
    lista.imprimir(); // 10 20 30 40

    return 0;
}
