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


class ListaCircular {
public:
    Node* head;
    ListaCircular() {
        head = new Node(0);
        head -> proximo = head;
    }

    void inserirInicio(int x) {
        Node* novo = new Node(x);
        Node* antigo = head -> proximo;
        head -> proximo = novo;
        novo -> proximo = antigo;
    }

    void inserir(int x) {
        Node* novo = new Node(x);
        Node* p = head;

        while (p -> proximo != head) {
            p = p -> proximo;
        }
        
        p -> proximo = novo;
        novo -> proximo = head;


    }

    void remover( int x) {
        Node* p = head;

        while ( p -> proximo != head && p -> proximo -> dado) {
            p = p -> proximo;
        }

        if (p != head) {
            Node* remover = p -> proximo;
            p -> proximo = remover -> proximo;
            delete remover;

        }
    } 

    void busca(int x) {
        Node* p = head -> proximo;

        while (p != head) {
            if (p -> dado == x) {
                cout << p->dado << endl;
            }
            p = p -> proximo;
        }

        cout << "Elemento não encontrado na lista" << endl;

        

    }
};

int main () {
    return 0;
}