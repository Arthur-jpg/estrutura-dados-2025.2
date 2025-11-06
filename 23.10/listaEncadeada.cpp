#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* prox;
};

Node* inicio = nullptr;

void adicionar(int v) {
    Node* novo = new Node();
    novo->valor = v;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        Node* temp = inicio;
        while (temp->prox != nullptr)
            temp = temp->prox;
        temp->prox = novo;
    }
}

void mostrar() {
    Node* temp = inicio;
    while (temp != nullptr) {
        cout << temp->valor << " -> ";
        temp = temp->prox;
    }
    cout << "NULL" << endl;
}

void remover(int v) {
    // Lista vazia
    if (inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    // Caso especial: o valor está no início
    if (inicio->valor == v) {
        Node* temp = inicio;
        inicio = inicio->prox;
        delete temp;
        return;
    }

    // Procurar o anterior do nó que queremos remover
    Node* anterior = inicio;

    while (anterior->prox != nullptr && anterior->prox->valor != v)
        anterior = anterior->prox;

    // Se chegamos ao final e não encontramos
    if (anterior->prox == nullptr) {
        cout << "Valor nao encontrado!" << endl;
        return;
    }

    // Agora anterior->prox é o nó a ser removido
    Node* temp = anterior->prox;

    // Liga o anterior direto ao próximo do próximo
    anterior->prox = anterior->prox->prox;

    // Libera o nó removido
    delete temp;

    cout << "Valor " << v << " removido!" << endl;
}

int main() {
    adicionar(10);
    adicionar(20);
    adicionar(30);
    adicionar(40);

    mostrar();   // 10 -> 20 -> 30 -> 40 -> NULL

    remover(20);
    mostrar();   // 10 -> 30 -> 40 -> NULL

    remover(40);
    mostrar();   // 10 -> 30 -> NULL

    remover(10);
    mostrar();   // 30 -> NULL

    return 0;
}
