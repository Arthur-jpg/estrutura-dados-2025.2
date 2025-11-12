#include <iostream>
using namespace std;

// Estrutura de nó para árvore binária (usada como base para AVL/rotações)
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height; // armazenado por conveniência

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int obterAltura(Node* n) {
        return n ? n->height : 0;
    }

    // --- Assinaturas de rotações (deixe os corpos vazios para você implementar) ---
    // Rotação simples à esquerda: retorna o novo nó raiz da subárvore
    Node* rotacaoEsquerda(Node* x) {
        
        Node* y = x -> right;
        Node* t2 = y -> left;

        y -> left = x;
        x -> right = t2;

        x -> height = max(obterAltura(x->left), obterAltura(x->right)) + 1;
        y -> height = max(obterAltura(y->left), obterAltura(y -> right)) + 1;
        

        return y;
    }

    // Rotação simples à direita: retorna o novo nó raiz da subárvore
    Node* rotacaoDireita(Node* y) {

        Node* x = y -> left;
        Node* t2 = x -> right;

        x -> right = y;
        y -> left = t2;

        y -> height = max(obterAltura(y->left), obterAltura(y->right)) + 1;
        x -> height = max(obterAltura(x->left), obterAltura(x->right)) + 1;
        
        return x;


    }

    // Rotação dupla: esquerda-direita (LR)
    Node* rotacaoDuplaEsquerdaDireita(Node* node) {
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }

    // Rotação dupla: direita-esquerda (RL)
    Node* rotacaoDuplaDireitaEsquerda(Node* node) {
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }

    // Inserção simples (BST) sem rebalanceamento — mantém código compilável
    Node* inserirRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = inserirRec(node->left, key);
        } else if (key > node->key) {
            node->right = inserirRec(node->right, key);
        }
        // Não fazemos balanceamento aqui; as rotações estão disponíveis para você implementar
        return node;
    }

    void inserir(int key) {
        root = inserirRec(root, key);
    }

    // Percursos para auxiliar nos testes
    void preOrdem(Node* node) {
        if (node) {
            cout << node->key << " ";
            preOrdem(node->left);
            preOrdem(node->right);
        }
    }

    void emOrdem(Node* node) {
        if (node) {
            emOrdem(node->left);
            cout << node->key << " ";
            emOrdem(node->right);
        }
    }

    void posOrdem(Node* node) {
        if (node) {
            posOrdem(node->left);
            posOrdem(node->right);
            cout << node->key << " ";
        }
    }

    void imprimirPre() { cout << "Pré-Ordem: "; preOrdem(root); cout << "\n"; }
    void imprimirIn()  { cout << "Em-Ordem: ";  emOrdem(root);  cout << "\n"; }
    void imprimirPost(){ cout << "Pós-Ordem: ";  posOrdem(root); cout << "\n"; }
};

int main() {
    // Arquivo-esqueleto para rotações. Insira nós e implemente as rotações nas funções marcadas como TODO.
    AVLTree tree;
    // exemplo de inserção (opcional):
    // tree.inserir(50);
    // tree.inserir(25);

    cout << "Arquivo criado: implemente as rotacoes em rotacaoEsquerda/rotacaoDireita/...\n";
    return 0;
}
