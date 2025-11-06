#include <iostream>

// Estrutura de nó para árvore binária de busca (BST)
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Cria um novo nó
Node* createNode(int key) {
    return new Node(key);
}

Node* minValueNode(Node* node) {
    Node* atual = node;
    if (atual -> left != nullptr) {
        atual = atual -> left;
    }
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root -> key) {
        root -> left = insert(root -> left, key);
    } else if (key > root -> key) {
        root -> right = insert(root -> right, key);
    }

    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root -> key) {
        root -> left = remove(root -> left, key);
    } else if (key > root -> key) {
        root -> right = remove(root -> right, key);
    } else {
        if (root -> left == nullptr && root -> right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root -> right == nullptr) {
            Node* temp = root -> left;
            delete root;
            return temp;
        } else if (root -> left == nullptr) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root -> right);
        root -> key = temp -> key;
        root -> right = remove(root -> right, temp -> key);

    }
}





// Pequeno main para teste manual rápido
int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 20, 40, 70, 60, 80};


    std::cout << "BST inorder antes da remoção: ";

    std::cout << "\n";

    // exemplo de remoções
    root = remove(root, 20); // remover folha
    root = remove(root, 30); // remover nó com um filho
    root = remove(root, 50); // remover nó com dois filhos (raiz)

    std::cout << "BST inorder depois da remoção: ";

    std::cout << "\n";

    return 0;
}