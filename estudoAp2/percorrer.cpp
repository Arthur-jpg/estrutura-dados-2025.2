#include <iostream>
using namespace std;

class Node {
public:
    int dado;
    Node* esq;
    Node* dir;
    
    Node() {
        dado = 0;
        esq = nullptr;
        dir = nullptr;
    }
    
    Node(int valor) {
        dado = valor;
        esq = nullptr;
        dir = nullptr;
    }
};

class Tree {
public:
    Node* root;
    
    Tree() {
        root = nullptr;
    }
    
    // Pré-Ordem: Raiz -> Esquerda -> Direita
    void PreOrdem(Node* node) {
        if (node != nullptr) {
            cout << node->dado << " "; /* visita raiz */
            PreOrdem(node->esq);
            PreOrdem(node->dir);
        }
    }
    
    // Em-Ordem: Esquerda -> Raiz -> Direita
    void EmOrdem(Node* node) {
        if (node != nullptr) {
            EmOrdem(node->esq);
            cout << node->dado << " "; /* visita raiz */
            EmOrdem(node->dir);
        }
    }
    
    // Pós-Ordem: Esquerda -> Direita -> Raiz
    void PosOrdem(Node* node) {
        if (node != nullptr) {
            PosOrdem(node->esq);
            PosOrdem(node->dir);
            cout << node->dado << " "; /* visita raiz */
        }
    }

    // Inserção em árvore binária de busca (iterativa)
    void inserir(int valor) {
        Node* novo = new Node(valor);
        if (root == nullptr) {
            root = novo;
            return;
        }
        Node* p = root;
        Node* pai = nullptr;
        while (p != nullptr) {
            pai = p;
            if (valor < p->dado) p = p->esq;
            else p = p->dir;
        }
        if (valor < pai->dado) pai->esq = novo;
        else pai->dir = novo;
    }
    
    // Métodos auxiliares para facilitar a chamada
    void percorrerPreOrdem() {
        cout << "=== Pré-Ordem ===" << endl;
        PreOrdem(root);
        cout << endl << endl;
    }
    
    void percorrerEmOrdem() {
        cout << "=== Em-Ordem ===" << endl;
        EmOrdem(root);
        cout << endl << endl;
    }
    
    void percorrerPosOrdem() {
        cout << "=== Pós-Ordem ===" << endl;
        PosOrdem(root);
        cout << endl << endl;
    }
};

int main() {
    Tree tree;
    
    // Inserir os números fornecidos na ordem especificada
    int valores[] = {50, 25, 2, 18, 10, 6, 7, 36, 32, 42, 150, 116, 200, 350, 430};
    int n = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < n; ++i) {
        tree.inserir(valores[i]);
    }

    // Testando os três percursos na árvore construída
    tree.percorrerPreOrdem();
    tree.percorrerEmOrdem();
    tree.percorrerPosOrdem();

    return 0;
}
