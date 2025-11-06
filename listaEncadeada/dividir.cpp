#include <iostream>
using namespace std;

class No {
public:
    int dado;
    No *proximo;

    No(int d, No *p = nullptr) {
        dado = d;
        proximo = p;
    }
};

class ListaEncadeada {
    No *head;

public:
    ListaEncadeada() {
        head = new No(0); // nó cabeça
    }

    void addFim(int valor) {
        No *novo = new No(valor);
        No *p = head;

        while (p->proximo != nullptr)
            p = p->proximo;

        p->proximo = novo;
    }

    void imprimir() {
        No *p = head->proximo;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }

    // Função que divide a lista e "retorna" as duas listas por referência
    void dividirEmDuasMetades(ListaEncadeada &primeira, ListaEncadeada &segunda) {
        // 1️⃣ Conta quantos elementos há na lista
        int total = 0;
        No *p = head->proximo;
        while (p != nullptr) {
            total++;
            p = p->proximo;
        }

        if (total == 0) {
            cout << "Lista vazia!" << endl;
            return;
        }

        int meio = total / 2;

        // 2️⃣ Percorre novamente e separa os valores nas duas listas
        p = head->proximo;
        int contador = 0;

        while (p != nullptr) {
            if (contador < meio)
                primeira.addFim(p->dado);
            else
                segunda.addFim(p->dado);

            contador++;
            p = p->proximo;
        }
    }
};

int main() {
    ListaEncadeada lista, metade1, metade2;

    lista.addFim(10);
    lista.addFim(20);
    lista.addFim(30);
    lista.addFim(40);
    lista.addFim(50);
    lista.addFim(60);

    cout << "Lista original: ";
    lista.imprimir();

    // A função preenche metade1 e metade2
    lista.dividirEmDuasMetades(metade1, metade2);

    cout << "Primeira metade: ";
    metade1.imprimir();

    cout << "Segunda metade: ";
    metade2.imprimir();

    return 0;
}
