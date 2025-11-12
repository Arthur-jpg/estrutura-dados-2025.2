#include <iostream>

using namespace std;

class Node {
public:
    int dado;
    Node* proximo;

    Node (int x) {
        this -> dado = x;
        this -> proximo = nullptr;
    }
};

class ListaEncadeada {
    Node* head;

public:
    ListaEncadeada() {
        this -> head = new Node(0);
    }

    void adicionarInicio(int x) {
        Node* novo = new Node(x);
        Node* antigo = head -> proximo;

        head -> proximo = novo;
        novo -> proximo = antigo;
    }

    void adicionarFinal(int x) {
        Node* novo = new Node(x);
        Node* p = head;
        while(p -> proximo != nullptr) {
            p = p -> proximo;
        }
        p -> proximo = novo;
    }

    void remover(int x) {
        Node* p = head;
        while ( p -> proximo != nullptr && p -> proximo -> dado != x) {
            p = p -> proximo;
        }

        if (p -> proximo != nullptr) {
            Node* remover = p -> proximo;
            p -> proximo = p -> proximo -> proximo;
            delete remover;

        }
    }

    void imprimir() {
        Node* p = head -> proximo;
        while (p != nullptr) {
            cout << p -> dado << endl;
            p = p -> proximo;
        }
    }
};


int main() {

    return 0;
}