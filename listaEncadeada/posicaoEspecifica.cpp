#include <iostream>
#include <vector>
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

    void removerPosicoes(vector<int> posicoes) {
        if (posicoes.empty()) return;

        // ordena as posições para remover em ordem crescente
        sort(posicoes.begin(), posicoes.end());

        int indiceAtual = 1; // começa no primeiro elemento (ignora o nó cabeça)
        int posicao = 0;   // índice dentro do vetor de posições
        No *anterior = this->head;
        No *atual = this->head->proximo;

        while (atual != nullptr && posicao < posicoes.size()) {
            if (indiceAtual == posicoes[posicao]) {
                // remove o nó atual
                anterior->proximo = atual->proximo;
                delete atual;
                atual = anterior->proximo;
                posicao++; // próxima posição a remover
            } else {
                anterior = atual;
                atual = atual->proximo;
            }
            indiceAtual++;
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
    lista.addFim(60);

    cout << "Lista original: ";
    lista.imprimir(); // 10 20 30 40 50 60

    vector<int> pos = {1, 3, 5};
    lista.removerPosicoes(pos);

    cout << "Lista após remover posições 1, 3 e 5: ";
    lista.imprimir(); // 20 40 60

    return 0;
}
