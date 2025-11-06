#include <iostream>
using namespace std;

// ...existing code...
class No {
public:
    int dado;
    No* esquerda;
    No* direita;

    No(int valor, No* esquerda = nullptr, No* direita = nullptr) {
        this->dado = valor;
        this->esquerda = esquerda;
        this->direita = direita;
    }
};

class arvore {
    No *head;
    void destruir(No* n) {
        if (!n) return;
        destruir(n->esquerda);
        destruir(n->direita);
        delete n;
    }
public:
    arvore() {
        this->head = nullptr;
    }

    ~arvore() {
        destruir(head);
    }

    void add(int x) {
        No* novo = new No(x);
        No* atual = head;
        No* pai = nullptr;

        if(atual == nullptr) {
            head = novo;
        } else {
            while(atual != nullptr) {
                pai = atual;
                if (x > atual -> dado) {
                    atual = atual -> direita;
                } else {
                    atual = atual -> esquerda;
                }
            }
            if (x < pai -> dado) {
                pai -> esquerda = novo;
            } else {
                pai -> direita = novo;
            }
        }


    }

    No* buscar(int x) {
        No *p = head;
        while (p != nullptr) {
            if (x == p->dado) return p;
            if (x < p->dado) p = p->esquerda;
            else p = p->direita;
        }
        return nullptr;
    }

    void imprimirEmOrdem(No* n) {
        if (!n) return;
        imprimirEmOrdem(n->esquerda);
        cout << n->dado << " ";
        imprimirEmOrdem(n->direita);
    }

    void imprimir() {
        imprimirEmOrdem(head);
        cout << "\n";
    }
};

int main() {
    arvore a;
    a.add(50);
    a.add(30);
    a.add(70);
    a.add(20);
    a.add(40);
    a.add(60);
    a.add(80);

    cout << "Árvore em ordem: ";
    a.imprimir();

    int chave = 60;
    No* encontrado = a.buscar(chave);
    if (encontrado) cout << "Encontrado: " << encontrado->dado << "\n";
    else cout << "Não encontrado: " << chave << "\n";

    chave = 25;
    encontrado = a.buscar(chave);
    if (encontrado) cout << "Encontrado: " << encontrado->dado << "\n";
    else cout << "Não encontrado: " << chave << "\n";

    return 0;
}