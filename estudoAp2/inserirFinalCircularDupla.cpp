#include <iostream>
using namespace std;

class Node {
public:
    int dado;
    Node* prox;
    Node* ant;
    
    Node() {
        dado = 0;
        prox = nullptr;
        ant = nullptr;
    }
    
    Node(int valor) {
        dado = valor;
        prox = nullptr;
        ant = nullptr;
    }
};

class ListaDuplamenteEncadeadaCircular {
public:
    Node* head;
    
    ListaDuplamenteEncadeadaCircular() {
        head = new Node();
        head->prox = head;
        head->ant = head;
    }
    
    void inserirFinal(int x) {
        Node* novo = new Node(x);
        Node* ultimo = head->ant;
        ultimo -> prox = novo;
        novo -> ant = ultimo;
        novo -> prox = head;
        head -> ant = novo;

    }
    
    bool buscar(int x) {
        Node* p;
        p = head->prox;
        while (p != head) {
            if (p->dado == x) {
                return true;
            }
            p = p->prox;
        }
        return false;
    }
    
    void removerLista(int x) {
        Node* p;
        p = head->prox;
        while (p != head) {
            if (p->dado == x) {
                break;
            }
            p = p->prox;
        }
        
        if (p != head) {
            p->prox->ant = p->ant;
            p->ant->prox = p->prox;
            delete p;
        }
    }
    
    void exibir() {
        Node* p = head->prox;
        cout << "Lista: ";
        while (p != head) {
            cout << p->dado << " ";
            p = p->prox;
        }
        cout << endl;
    }
    
    ~ListaDuplamenteEncadeadaCircular() {
        Node* p = head->prox;
        while (p != head) {
            Node* temp = p;
            p = p->prox;
            delete temp;
        }
        delete head;
    }
};

int main() {
    ListaDuplamenteEncadeadaCircular lista;
    
    // Teste suas implementações aqui
    
    return 0;
}
